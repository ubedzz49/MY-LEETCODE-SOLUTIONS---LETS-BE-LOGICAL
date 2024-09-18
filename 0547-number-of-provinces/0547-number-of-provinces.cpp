class Solution {
public:
void bfs(vector<vector<int>> adjl,int s,vector<bool>& universal){
    vector<bool> visited(adjl.size(),0);
    queue<int> q;
    q.push(s);
    visited[s]=1;
    universal[s]=1;
    while(!q.empty()){
        for(int i=0;i<adjl[q.front()].size();i++){
            if(visited[adjl[q.front()][i]]==0){
                visited[adjl[q.front()][i]]=1;
                universal[adjl[q.front()][i]]=1;
                q.push(adjl[q.front()][i]);
            }
        }
        q.pop();
    }
}

    int findCircleNum(vector<vector<int>>& isc) {
        vector<vector<int>> adjl(isc.size());
        for(int i=0;i<isc.size();i++){
            for(int j=0;j<isc[i].size();j++){
                if(isc[i][j]==1){
                    adjl[i].push_back(j);
                }
            }
        }
        vector<bool> universal(adjl.size(),0);
        int c=0;
        for(int i=0;i<adjl.size();i++){
            if(universal[i]==0){
                c++;
                bfs(adjl,i,universal);
            }
        }
        return c;
    }
};