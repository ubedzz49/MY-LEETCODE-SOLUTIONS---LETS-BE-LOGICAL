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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mpp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        if(root==nullptr) return {};
        q.push(make_pair(make_pair(0,0),root));
        while(!q.empty()){
            int lvl=q.front().first.second;
            int h=q.front().first.first;
            TreeNode* node=q.front().second;
            q.pop();
            mpp[lvl][h].push_back(node->val);
            if(node->left!=nullptr) q.push(make_pair(make_pair(h+1,lvl-1),node->left));
            if(node->right!=nullptr) q.push(make_pair(make_pair(h+1,lvl+1),node->right));
        }
        vector<vector<int>> ans;
        for(auto it:mpp) {
            vector<int> a;
            for(auto iit:it.second){
                sort(iit.second.begin(),iit.second.end());
                for(auto i:iit.second) a.push_back(i);
            }
            ans.push_back(a);
        }
        return ans;
    }
};