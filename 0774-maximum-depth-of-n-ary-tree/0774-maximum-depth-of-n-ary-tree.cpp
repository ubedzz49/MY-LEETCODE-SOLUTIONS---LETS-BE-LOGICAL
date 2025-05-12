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
    int maxDepth(Node* root) {
        if(!root) return 0;
        int ans=1;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            int h=q.front().second;
            ans=max(ans,h);
            Node* nd=q.front().first;
            q.pop();
            for(auto it:nd->children) q.push(make_pair(it,h+1));
        }
        return ans;
    }
};