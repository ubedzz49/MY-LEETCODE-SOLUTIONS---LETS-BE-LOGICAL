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
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,bool>>> q;
        if(root->left) q.push(make_pair(root->left,make_pair(1,0)));
        if(root->right) q.push(make_pair(root->right,make_pair(1,1)));
        int ans=0;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int s=q.front().second.first;
            bool b=q.front().second.second;
            //cout<<node->val<<" "<<s<<" "<<b<<endl;
            q.pop();
            ans=max(ans,s);
            if(b==1){
                if(node->left) q.push(make_pair(node->left,make_pair(s+1,!b)));
                if(node->right) q.push(make_pair(node->right,make_pair(1,b)));
            }
            else{
                if(node->left) q.push(make_pair(node->left,make_pair(1,b)));
                if(node->right) q.push(make_pair(node->right,make_pair(s+1,!b)));
            }
        }
        return ans;
    }
};