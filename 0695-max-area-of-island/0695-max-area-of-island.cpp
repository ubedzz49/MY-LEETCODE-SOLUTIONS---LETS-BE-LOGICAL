class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        vector<int> x={-1,+1,0,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( grid[i][j]!=0){
                    int curr=0;
                   q.push(make_pair(i,j));
                   grid[i][j]=0;
                   while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                        curr+=1;
                        for(int ii=0;ii<4;ii++){
                            int xc=r+x[ii];
                            int yc=c+x[3-ii];
                            if(xc>=0 && yc>=0 && xc<grid.size() && yc<grid[0].size() && grid[xc][yc]!=0){
                                grid[xc][yc]=0;
                                q.push(make_pair(xc,yc));
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