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
    int lh=fn(root->left);
    int rh=fn(root->right);
    int h=max(lh,rh)+1;
    if(abs(lh-rh)>1 || lh==-1 || rh==-1) return -1;
    else return h;
}
    bool isBalanced(TreeNode* root) {
        if(fn(root)==-1) return false;
        return true;
    }
};