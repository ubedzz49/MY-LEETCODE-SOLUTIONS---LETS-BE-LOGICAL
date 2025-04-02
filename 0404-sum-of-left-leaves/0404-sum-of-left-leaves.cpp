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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        int ans=0;
        if(root)q.push(root);
        while(!q.empty()){
            if(q.front()->left){
                q.push(q.front()->left);
                if(q.front()->left->left==nullptr && q.front()->left->right==nullptr) ans+=q.front()->left->val;
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ans;
    }
};