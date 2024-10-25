class Solution {
public:
void dfs(vector<vector<int>>& ans,vector<bool>& visited,vector<int>& parent,vector<int>& low,vector<int>& dis,int node,vector<vector<int>>& adj,int dt){
    for(auto it:adj[node]){
        if(it==parent[node]) continue;
        if(!visited[it]){
            parent[it]=node;
            visited[it]=1;
            dis[it]=dt+1;
            low[it]=dt+1;
            dfs(ans,visited,parent,low,dis,it,adj,dt+1);
            if(low[it]>dis[node]) {ans.push_back({it,node});
            }
        }
        low[node]=min(low[node],low[it]);
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> ans;
        vector<int> parent(n,-1);
        vector<int> low(n,INT_MAX);
        vector<int> dis(n,-1);
        vector<bool> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto it:conn){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        visited[1]=1;
        dis[1]=1;
        low[1]=1;
        dfs(ans,visited,parent,low,dis,1,adj,1);
        return ans;
    }
};