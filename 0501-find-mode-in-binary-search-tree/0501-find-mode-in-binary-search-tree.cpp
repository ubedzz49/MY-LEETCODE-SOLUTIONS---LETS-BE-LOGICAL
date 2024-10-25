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
void tra(map<int,int>& mpp,TreeNode* root){
    if(root==nullptr) return;
    mpp[root->val]++;
    tra(mpp,root->left);
    tra(mpp,root->right);
}
    vector<int> findMode(TreeNode* root) {
        map<int,int> mpp;
        vector<int> ans;
        int mx=-1;
        tra(mpp,root);
        for(auto it:mpp){
            mx=max(mx,it.second);
        }
        for(auto it:mpp){
            if(it.second==mx) ans.push_back(it.first);
        }
        return ans;
    }
};