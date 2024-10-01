class Solution {
public:
bool dfs(int st,vector<vector<int>>& adj,vector<bool>& uv,vector<bool>& pv){
    pv[st]=1;
    uv[st]=1;
    for(int i:adj[st]){
        if(pv[i]==1){
            return true;
        }
        if(!uv[i]){
            if(dfs(i,adj,uv,pv)){
                return true;
            }
        }
    }
    pv[st]=0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<bool> uv(adj.size(),0);
        vector<bool> pv(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(uv[i]==0){
            dfs(i,adj,uv,pv);
            }
        }
        vector<int> ans;
        for(int i=0;i<pv.size();i++){
            if(pv[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};