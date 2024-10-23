/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int p1=-1;
        int p2=-2;
        int l1=-1;
        int l2=-1;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            int n=q.size();
            while(n>0){
                n--;
                TreeNode* node=q.front().first;
                int lvl=q.front().second;
                q.pop();
                if(node->left!=nullptr){
                    if(node->left->val==x){
                        p1=node->val;
                        l1=lvl;
                    }
                    if(node->left->val==y){
                        p2=node->val;
                        l2=lvl;
                    }
                    q.push(make_pair(node->left,lvl+1));
                }
                if(node->right!=nullptr){
                    if(node->right->val==x){
                        p1=node->val;
                        l1=lvl;
                    }
                    if(node->right->val==y){
                        p2=node->val;
                        l2=lvl;
                    }
                    q.push(make_pair(node->right,lvl+1));
                }
            }
        }
        cout<<p1<<" "<<p2<<endl;
        cout<<l1<<" "<<l2;
        if(l1==l2 && p1!=p2){
            return 1;
        }
        return 0;
    }
};