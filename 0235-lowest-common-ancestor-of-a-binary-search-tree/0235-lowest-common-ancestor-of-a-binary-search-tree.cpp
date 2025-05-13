/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* ans=nullptr;
int fn(TreeNode*& root,TreeNode*& p,TreeNode*& q){
    if(root==nullptr || ans!=nullptr) return 0;
    int v=0;
    if(root==p || root==q) v=1;
    int l=fn(root->left,p,q);
    int r=fn(root->right,p,q);
    if(v+r+l==2 && ans==nullptr) ans=root;
    return v+l+r;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fn(root,p,q);
        return ans;
    }
};