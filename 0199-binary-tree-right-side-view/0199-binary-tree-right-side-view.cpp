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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            while(s>0){
                s--;
                TreeNode* nd=q.front();
                q.pop();
                if(nd->left!=nullptr) q.push(nd->left);
                if(nd->right!=nullptr) q.push(nd->right);
                if(s==0) ans.push_back(nd->val);
            }
        }
        return ans;
    }
};