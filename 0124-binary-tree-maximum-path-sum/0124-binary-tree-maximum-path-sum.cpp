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
int fn(TreeNode*& root){
    if(root==nullptr) return 0;
    int l=fn(root->left);
    int r=fn(root->right);
    return max(max(l,r)+root->val,max(root->val,0));
}
void mfn(TreeNode*& root,int& ans){
    if(root==nullptr) return;
    ans=max(ans,fn(root->left)+fn(root->right)+root->val);
    mfn(root->right,ans);
    mfn(root->left,ans);
}
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        mfn(root,ans);
        return ans;
    }
};