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
void fn(vector<string>& ans,TreeNode*& root,string s){
    if(root==nullptr){
        return;
    }
    s+="->";
    s+=to_string(root->val);
    fn(ans,root->left,s);
    fn(ans,root->right,s);
    if(root->left==nullptr && root->right==nullptr) ans.push_back(s);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr) ans.push_back(s);
        fn(ans,root->left,s);
        fn(ans,root->right,s);
        return ans;
    }
};