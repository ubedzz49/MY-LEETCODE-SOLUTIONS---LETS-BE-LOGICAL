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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool b=false;
        while(!q.empty()){
            int s=q.size();
            while(s>0){
                s--;
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    if(b) return false;
                     q.push(node->left);
                }
                else b=true;
                if(node->right) {
                    if(b) return false;
                    q.push(node->right);
                }
                else b=true;
            }
        }
        return true;
    }
};