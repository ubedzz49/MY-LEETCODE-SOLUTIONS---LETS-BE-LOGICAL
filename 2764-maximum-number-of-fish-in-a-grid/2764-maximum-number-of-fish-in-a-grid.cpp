class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool> (grid[0].size(),0));
        vector<int> x={-1,+1,0,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) vis[i][j]=1;
                if(vis[i][j]==0 && grid[i][j]!=0){
                    int curr=0;
                   q.push(make_pair(i,j));
                   vis[i][j]=1;
                   while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    if(grid[r][c]==0){
                        vis[r][c]=1;
                    }
                    else{
                        curr+=grid[r][c];
                        for(int ii=0;ii<4;ii++){
                            int xc=r+x[ii];
                            int yc=c+x[3-ii];
                            if(xc>=0 && yc>=0 && xc<grid.size() && yc<grid[0].size() && vis[xc][yc]==0){
                                vis[xc][yc]=1;
                                q.push(make_pair(xc,yc));
                            }
                        }
                    }
                   } 
                   ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};