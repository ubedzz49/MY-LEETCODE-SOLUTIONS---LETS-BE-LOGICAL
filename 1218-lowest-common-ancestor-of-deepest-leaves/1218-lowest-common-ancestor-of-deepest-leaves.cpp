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
bool check(TreeNode* root,unordered_set<TreeNode*> stt){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        if(stt.find(q.front())!=stt.end()) stt.erase(q.front());
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    if(stt.empty()) return 1;
    return 0;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> lf;
        queue<TreeNode*> q;
        q.push(root);
        lf={root};
        while(!q.empty()){
            int n=q.size();
            lf={};
            while(n>0){
                n--;
                lf.push_back(q.front());
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        unordered_set<TreeNode*> stt;
        for(auto it:lf) stt.insert(it);

        TreeNode* ans=root;
        //queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        if(check(q.front(),stt)) ans=q.front();
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }

        return ans;
    }
};