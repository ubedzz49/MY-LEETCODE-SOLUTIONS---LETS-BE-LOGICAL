class Solution {
public:
void dfs(vector<bool>& visited,vector<vector<int>>& ans,vector<int>& path,int dst,vector<vector<int>>& adj){
    int n=path[path.size()-1];
    for(auto i:adj[n]){
        if(i==dst){
            path.push_back(dst);
            ans.push_back(path);
            path.pop_back();
        }else if(!visited[i]){
            visited[i]=1;
            path.push_back(i);
            dfs(visited,ans,path,dst,adj);
            path.pop_back();
            visited[i]=0;
        }
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),0);
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        visited[0]=1;
        dfs(visited,ans,path,graph.size()-1,graph);
        return ans;
    }
};