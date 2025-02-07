class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    vis[i][j]=1;
                    vector<int> dir={-1,+1,0,0};
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r=ii+dir[k];
                            int c=jj+dir[3-k];
                            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]=='1' && !vis[r][c]){
                                q.push(make_pair(r,c));
                                vis[r][c]=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};