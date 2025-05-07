class Solution {
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n=move.size();
        int m=move[0].size();
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
        queue<vector<int>> q;
        q.push({0,0,0});
        vector<int> dir={-1,+1,0,0};
        while(!q.empty()){
            int d=q.front()[0];
            int i=q.front()[1];
            int j=q.front()[2];
            q.pop();
            for(int ii=0;ii<4;ii++){
                int r=i+dir[ii];
                int c=j+dir[3-ii];
                if(r>=0 && c>=0 && r<n && c<m && dp[r][c]>max(d+1,move[r][c]+1)){
                    dp[r][c]=max(d+1,move[r][c]+1);
                    q.push({dp[r][c],r,c});
                }
            }
        }
        return dp[n-1][m-1];
    }
};