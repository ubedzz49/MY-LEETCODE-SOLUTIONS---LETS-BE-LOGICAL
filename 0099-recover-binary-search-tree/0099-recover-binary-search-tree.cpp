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
void fn(TreeNode*& root,vector<int>& ans){
    if(root==nullptr) return;
    fn(root->left,ans);
    ans.push_back(root->val);
    fn(root->right,ans);
}
void change(TreeNode*& root,int a,int b){
    if(root==nullptr) return;
    if(root->val==a) root->val=b;
    else if(root->val==b) root->val=a;
    change(root->left,a,b);
    change(root->right,a,b);
}
    void recoverTree(TreeNode*& root) {
        vector<int> ans,vals,ans2;
        
        fn(root,ans);ans2=ans;
        sort(ans2.begin(),ans2.end());
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.size();j++){
                if(i==j) continue;
                swap(ans[i],ans[j]);
                if(ans==ans2){
                    vals.push_back(ans[i]);
                    vals.push_back(ans[j]);
                    break;
                }
                swap(ans[i],ans[j]);
            }
        }
        change(root,vals[0],vals[1]);
    }
};