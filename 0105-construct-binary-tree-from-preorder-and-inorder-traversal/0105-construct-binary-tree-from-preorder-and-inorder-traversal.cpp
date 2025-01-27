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
void make(vector<int>& pre,vector<int>& ino,TreeNode*& root,int& pi,int i,int j){
    if(i>j) return;
    TreeNode* newnode=new TreeNode;
    newnode->val=pre[pi];
    newnode->left=nullptr;
    newnode->right=nullptr;
    root=newnode;
    int ind=-1;
    for(int ii=i;ii<=j;ii++){
        if(ino[ii]==pre[pi]){
            ind=ii;
            break;
        }
    }
    pi++;
    make(pre,ino,root->left,pi,i,ind-1);
    make(pre,ino,root->right,pi,ind+1,j);
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        int i=0;
        int j=pre.size()-1;
        int pi=0;
        TreeNode* root=nullptr;
        make(pre,ino,root,pi,i,j);
        return root;
    }
};