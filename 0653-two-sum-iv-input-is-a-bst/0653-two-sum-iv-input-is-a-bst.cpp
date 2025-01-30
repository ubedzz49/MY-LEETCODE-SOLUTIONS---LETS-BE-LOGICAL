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
void vc(TreeNode* root,vector<int>& vec){
    if(root==nullptr){
        return;
    }
    vc(root->left,vec);
    vec.push_back(root->val);
    vc(root->right,vec);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        vc(root,vec);
        int i=0;
        int j=vec.size()-1;
        while(i<j){
            if(vec[i]+vec[j]==k){
                return true;
            }
            if(vec[i]+vec[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};