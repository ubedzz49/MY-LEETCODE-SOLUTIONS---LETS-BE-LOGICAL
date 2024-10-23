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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> lvlsms;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int lvlsm=0;
            while(n>0){
                n--;
                lvlsm+=q.front()->val;
                if(q.front()->left!=nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=nullptr){
                    q.push(q.front()->right);
                }
                q.pop(); 
            }
            lvlsms.push_back(lvlsm);
            cout<<lvlsms.size()<<" "<<lvlsm<<endl;
            
        }
        lvlsms.push_back(0);
        queue<pair<TreeNode*,int>> que;
        root->val=0;
        que.push(make_pair(root,1));
        while(!que.empty()){
            int n=que.size();
            int l=lvlsms[que.front().second];
            while(n>0){
                n--;
                pair<TreeNode*,int> p=que.front();
                TreeNode* node=p.first;
                int csum=0;
                if(node->left!=nullptr) csum+=node->left->val;
                if(node->right!=nullptr) csum+=node->right->val;
                if(node->left!=nullptr) {node->left->val=l-csum;
                que.push(make_pair(node->left,que.front().second+1));}
                if(node->right!=nullptr) {node->right->val=l-csum;
                que.push(make_pair(node->right,que.front().second+1));}
                
                
                que.pop();
            }
        }
        return root;
    }
};