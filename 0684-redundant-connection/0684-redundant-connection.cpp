class Solution {
public:
bool iscon(vector<vector<bool>>& adj){
    int n=adj.size();
    vector<bool> vis(n,0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=1;i<n;i++) if(adj[node][i]==1 && vis[i]==0) {q.push(i); vis[i]=1;}
    }
    for(int i=1;i<n;i++) if(vis[i]==0) return 0;
    return 1;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=0;
        for(auto it:edges){
            n=max(n,max(it[1],it[0]));
        }
        n++;
        vector<vector<bool>> adj(n,vector<bool>(n,0));
        for(auto it:edges){
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
        }

        reverse(edges.begin(),edges.end());
        for(auto it:edges){
            adj[it[0]][it[1]]=0;
            adj[it[1]][it[0]]=0;
            if(iscon(adj)) return it;
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
        }
        return {};
    }
};