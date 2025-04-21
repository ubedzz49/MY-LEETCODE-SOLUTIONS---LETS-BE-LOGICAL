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
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> nums;
        while(!q.empty()){
            nums.push_back(q.front()->val);
            if(q.front()->right) q.push(q.front()->right);
            if(q.front()->left) q.push(q.front()->left);
            q.pop();
        }

        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=1;i<nums.size();i++){
            ans=min(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};