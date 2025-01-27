class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vector<bool> ans;
        for(auto it:pre){
            vis[it[0]][it[1]]=1;
        }
        for(auto it: queries){
            queue<int> q;
            q.push(it[0]);
            vector<bool> visi(n,0);
            visi[it[0]]=1;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    if(vis[v][i]==1 && visi[i]==0){
                        vis[it[0]][i]=1;
                        visi[i]=1;
                        q.push(i);
                        if(i==it[1]) break;
                    }
                }
            }
            ans.push_back(vis[it[0]][it[1]]);
        }
        return ans;
    }
};