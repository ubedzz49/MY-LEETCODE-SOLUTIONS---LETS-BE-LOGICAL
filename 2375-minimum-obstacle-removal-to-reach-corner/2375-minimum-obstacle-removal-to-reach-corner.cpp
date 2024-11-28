class Solution {
public:
bool ispos(int i,int j,int r,int c){
    if(i>=0 && j>=0 && i<r && j<c) return 1;
    return 0;
}
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),INT_MAX));
        dp[0][0]=0;
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        q.push(make_pair(0,0));
        while(!q.empty()){
            vector<int> drow={-1,+1,0,0};
            vector<int> dcol={0,0,-1,+1};
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int i1=i+drow[k];
                int j1=j+dcol[k];
                if(!ispos(i1,j1,m,n)) continue;
                int obs=0;
                if(grid[i1][j1]==1) obs=1;
                if(dp[i1][j1]>dp[i][j]+obs){
                    dp[i1][j1]=dp[i][j]+obs;
                    q.push(make_pair(i1,j1));
                }
            }
        }
        return dp[m-1][n-1];
    }
};