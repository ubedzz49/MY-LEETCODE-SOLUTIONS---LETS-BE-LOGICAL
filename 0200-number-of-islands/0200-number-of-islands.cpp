class Solution {
public:

bool ispos(int i,int j, vector<vector<char>>& grid){
    if(i>=0 && i<grid.size() && j>=0 && j<grid[i].size() && grid[i][j]=='1'){
        return true;
    }
    return false;
}
    int numIslands(vector<vector<char>>& grid) {

    int ans=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='0'){
                continue;
            }
            ans++;
            queue<pair<int,int>> q;
            q.push({i,j});
            grid[i][j]='0';
            
            while(!q.empty()){
            int t=q.front().first;
            int d=q.front().second;
                if(ispos(t+1,d,grid)){
                    q.push({t+1,d});
                    grid[t+1][d]='0';
                }
                if(ispos(t-1,d,grid)){
                    q.push({t-1,d});
                    grid[t-1][d]='0';
                }
                if(ispos(t,d+1,grid)){
                    q.push({t,d+1});
                    grid[t][d+1]='0';
                }
                if(ispos(t,d-1,grid)){
                    q.push({t,d-1});
                    grid[t][d-1]='0';
                }
                cout<<t<<" "<<d<<endl;
                q.pop();
            }
        }
    }
    return ans;
    }
};