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
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        queue<vector<int>> vq;
        queue<pair<TreeNode*,int>> tq;
        if(root!=nullptr){
            tq.push(make_pair(root,root->val));
            vq.push({root->val});
        }
        vector<vector<int>> ans;
        while(!tq.empty()){
            vector<int> v=vq.front();
            vq.pop();
            TreeNode* node=tq.front().first;
            int s=tq.front().second;
            tq.pop();
            if(node->left==nullptr && node->right==nullptr){
                if(s==k) ans.push_back(v);
            }
            if(node->left){
                v.push_back(node->left->val);
                vq.push(v);
                v.pop_back();
                tq.push(make_pair(node->left,s+node->left->val));
            }
            if(node->right){
                v.push_back(node->right->val);
                vq.push(v);
                v.pop_back();
                tq.push(make_pair(node->right,s+node->right->val));
            }
        }
        return ans;
    }
};