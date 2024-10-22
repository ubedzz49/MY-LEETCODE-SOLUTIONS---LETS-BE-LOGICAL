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
    int maxLevelSum(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        long long ans=root->val;
        int l=0;
        int ansl=1;
        while(!q.empty()){
            l++;
            long long sum=0;
            int n=q.size();
            while(n>0){
                n--;
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            if(sum>ans){
                ansl=l;
            }
            ans=max(sum,ans);
            
        }
        return ansl;
    }
};