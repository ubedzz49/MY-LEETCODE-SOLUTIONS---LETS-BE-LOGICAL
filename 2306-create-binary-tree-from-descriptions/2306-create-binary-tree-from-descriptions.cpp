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
void ins(TreeNode*& root,int v){
    TreeNode* newnode=new TreeNode;
    newnode->val=v;
    newnode->left=nullptr;
    newnode->right=nullptr;
    root=newnode;
}
    TreeNode* createBinaryTree(vector<vector<int>>& ds) {
        unordered_map<int,bool> mpp;
        unordered_map<int,int> left,right;
        for(auto it:ds) mpp[it[1]]=1;
        int val=0;
        for(auto it:ds){
            if(mpp[it[0]]==0) val=it[0];
            if(it[2]==1) left[it[0]]=it[1];
            else right[it[0]]=it[1];
        }
        TreeNode* ans=nullptr;
        ins(ans,val);
        queue<TreeNode*> q;
        q.push(ans);
        while(!q.empty()){
            TreeNode* node=q.front();
            int value=node->val;
            q.pop();
            if(left[value]!=0){ ins(node->left,left[value]); q.push(node->left);}
            if(right[value]!=0){ ins(node->right,right[value]); q.push(node->right);}
        }
        return ans;
    }
};