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
void make(vector<int>& nums,int i,int j,TreeNode*& root){
    if(i>j) return;
    int ind=(i+j)/2;
    TreeNode* newnode=new TreeNode;
    newnode->val=nums[ind];
    newnode->left=nullptr;
    newnode->right=nullptr;
    root=newnode;
    make(nums,i,ind-1,root->left);
    make(nums,ind+1,j,root->right);
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans=nullptr;
        make(nums,0,nums.size()-1,ans);
        return ans;
    }
};