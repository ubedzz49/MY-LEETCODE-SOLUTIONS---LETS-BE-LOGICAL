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
   void fn(TreeNode*& root, vector<int>& pre, int& i, int p) {
        if (i==pre.size() || pre[i] > p) return;
        if (!root) {
            root=new TreeNode(pre[i++]);
        }
        if (i < pre.size() && pre[i] < root->val) 
            fn(root->left,pre,i,root->val);
        
        if (i<pre.size() && pre[i]>root->val && pre[i]<p)
            fn(root->right,pre,i,p); 
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* ans=nullptr;
        int i=0;
        int p=INT_MAX;
        fn(ans,pre,i,p);
        return ans;
    }
};