class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        vector<int> dir={-1,+1,0,0};
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                    grid[i][j]=2;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int nr=row+dir[i];
                            int nc=col+dir[3-i];
                            if(nr>=0 & nc>=0 && nr<grid.size() && nc<grid[0].size()){
                                if(grid[nr][nc]==1) {q.push(make_pair(nr,nc)); grid[nr][nc]=2;}
                                else if(grid[nr][nc]==0) ans++;
                                else continue;
                            }
                            else ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};