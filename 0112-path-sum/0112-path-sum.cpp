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
bool dfs(int cs,int& ts,TreeNode* root){
    if(root==nullptr){
        return false;
    }
    if(root!=nullptr && root->left==nullptr && root->right==nullptr){
        if(cs+root->val==ts){
            return true;
        }
        return false;
    }
    int v=root->val;
    if(root->left!=nullptr){
        if(dfs(cs+root->val,ts,root->left)){
            return true;
        }
    }
    if(root->right!=nullptr){
        if(dfs(cs+root->val,ts,root->right)){
            return true;
        }
    }
    return false;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int cs=0;
        bool b=dfs(cs,targetSum,root);
        return b;
    }
};