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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push(make_pair(root,root));
        unordered_map<TreeNode*,bool> last;
        while(!q.empty()){
            unordered_map<TreeNode*,bool> last2;
            last=last2;
            int s=q.size();
            while(s>0){
                s--;
                last[q.front().first]=1;
                parent[q.front().first]=q.front().second;
                if(q.front().first->left) q.push(make_pair(q.front().first->left,q.front().first));
                if(q.front().first->right) q.push(make_pair(q.front().first->right,q.front().first));
                q.pop();
            }
        }
        TreeNode* ans=nullptr;
        bool b=false;
        if(last.size()==1){
            for(auto it:last){
                return it.first;
            }
        }
        while(b==false){
            unordered_map<TreeNode*,bool> last2;
            for(auto it:last){
                last2[parent[it.first]]=1;
                ans=parent[it.first];
            }
            last=last2;
            if(last.size()==1) b=true;
        }
        return ans;
    }
};