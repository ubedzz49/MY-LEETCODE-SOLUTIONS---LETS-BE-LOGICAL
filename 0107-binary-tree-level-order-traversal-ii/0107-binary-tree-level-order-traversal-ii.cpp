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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<int,TreeNode*>> q;
        vector<vector<int>> ans(1);
        q.push(make_pair(0,root));
        while(!q.empty()){
            TreeNode* node=q.front().second;
            int n=q.front().first;
            if(n==ans.size()) ans.push_back({node->val});
            else ans[n].push_back(node->val);
            if(node->left!=nullptr) q.push(make_pair(n+1,node->left));
            if(node->right!=nullptr) q.push(make_pair(n+1,node->right));
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};