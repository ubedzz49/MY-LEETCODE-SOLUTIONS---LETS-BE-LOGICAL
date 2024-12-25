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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int c=-1;
        while(!q.empty()){
            ans.push_back(INT_MIN);
            c++;
            int n=q.size();
            while(n>0){
                n--;
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                ans[c]=max(ans[c],q.front()->val);
                q.pop();
            }
        }
        return ans;
    }
};