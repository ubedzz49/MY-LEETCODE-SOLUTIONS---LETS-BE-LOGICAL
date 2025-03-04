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
int p=0;
void fn(vector<int>& pre,vector<int>& in,int si,int ei,TreeNode*& root){
    if(si>ei) return;
    root=new TreeNode;
    root->val=pre[p];
    root->left=nullptr;
    root->right=nullptr;
    p++;
    int ind=-1;
    for(int i=si;i<=ei;i++){
        if(in[i]==pre[p-1]) ind=i;
    }
    fn(pre,in,si,ind-1,root->left);
    fn(pre,in,ind+1,ei,root->right);
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        TreeNode* ans=nullptr;
        fn(pre,in,0,pre.size()-1,ans);
        return ans;
    }
};