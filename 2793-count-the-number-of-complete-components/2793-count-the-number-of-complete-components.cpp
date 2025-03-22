class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n, vector<int> (0));
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int c=0;
        vector<bool> vis(n,0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                int vno=0,eno=0;
                vis[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    vno++;
                    int v=q.front();
                    q.pop();
                    for(auto it:adj[v]){
                        eno++;
                        if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);}
                    }
                }
                if(eno==(vno*(vno-1))) c++;
            }
        }
        return c;
    }
};