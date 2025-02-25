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
void fn(TreeNode*& root, int k, int& ans) {
        queue<pair<TreeNode*,long long>> tq;
        if(root!=nullptr){
            tq.push(make_pair(root,root->val));
        }
        while(!tq.empty()){
            TreeNode* node=tq.front().first;
            long long s=tq.front().second;
            tq.pop();
            if(s==k) ans++;
            if(node->left){
                tq.push(make_pair(node->left,s+node->left->val));
            }
            if(node->right){
                tq.push(make_pair(node->right,s+node->right->val));
            }
        }
}
void mfn(TreeNode*& root,int k,int& ans){
    if(root==nullptr) return;
    fn(root,k,ans);
    mfn(root->left,k,ans);
    mfn(root->right,k,ans);
}
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        mfn(root,targetSum,ans);
        return ans;
    }
};