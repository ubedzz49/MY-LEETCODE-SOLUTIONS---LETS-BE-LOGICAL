/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        if(root==nullptr) return {};
        ans.push_back({root->val});
        while(!q.empty()){
            vector<int> a;
            int qs=q.size();
            for(int i=0;i<qs;i++){
                Node* nd=q.front();
                q.pop();
                for(auto it:nd->children){
                    a.push_back(it->val);
                    q.push(it);
                }
            }
            if(a.size()>0)ans.push_back(a);
        }
        return ans;
    }
};