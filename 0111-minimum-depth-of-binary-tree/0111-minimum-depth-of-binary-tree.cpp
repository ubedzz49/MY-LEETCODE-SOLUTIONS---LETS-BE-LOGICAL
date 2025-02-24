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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            if(q.front().first->right==nullptr && q.front().first->left==nullptr) {return q.front().second;}
            if(q.front().first->left) q.push(make_pair(q.front().first->left,q.front().second+1));
            if(q.front().first->right) q.push(make_pair(q.front().first->right,q.front().second+1));
            q.pop();
        }
        return 0;
    }
};