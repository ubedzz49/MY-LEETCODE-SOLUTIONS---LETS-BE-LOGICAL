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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=nullptr){
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right!=nullptr){
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        queue<int> qq;
        unordered_map<int,bool> mpp;
        mpp[start]=1;
        int ans=0;
        qq.push(start);
        while(!qq.empty()){
            int s=qq.size();
            ans++;
            while(s>0){
                s--;
                int a=qq.front();
                qq.pop();
                for(auto it:adj[a]){
                    if(!mpp[it]) {
                        mpp[it]=1;
                        qq.push(it);
                    }
                }
            }
        }
        return ans-1;
    }
};