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
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,root->val));
        int ans=0;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int s=q.front().second;
            q.pop();
            if(node->left==nullptr && node->right==nullptr) ans+=s;
            if(node->left) q.push(make_pair(node->left,(s*10)+node->left->val));
            if(node->right) q.push(make_pair(node->right,(s*10)+node->right->val));
        }
        return ans;
    }
};