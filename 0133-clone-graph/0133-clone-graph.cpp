/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int,bool> vis;
        queue<Node*> q;
        unordered_map<int,vector<int>> adj;
        if(node==nullptr) return nullptr;
        q.push(node);
        vis[node->val]=1;
        while(!q.empty()){
            Node* nd=q.front();
            q.pop();
            for(auto it:nd->neighbors){
                adj[nd->val].push_back(it->val);
                if(!vis[it->val]){
                    q.push(it);
                    vis[it->val]=1;
                }
            }
        }
        for(auto it:adj){
            cout<<it.first<<" -> ";
            for(auto i:it.second) cout<<i<<" ";
            cout<<endl;
        }
        Node* ans;
        map<int,Node*> mpp;
        for(auto it:vis){
            if(it.second) {
                Node* newnode= new Node;
                newnode->val=it.first;
                newnode->neighbors={};
                mpp[it.first]=newnode;
            }
        }
        for(auto it:adj){
            for(auto i:it.second){
                mpp[it.first]->neighbors.push_back(mpp[i]);
            }
        }
        return mpp[node->val];
    }
};