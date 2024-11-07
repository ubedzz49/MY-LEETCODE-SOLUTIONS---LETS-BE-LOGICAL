class Solution {
public:
bool ispos(int i,int j,int m,int n){
    if(i<m && i>=0 && j>=0 && j<n) return true;
    return false;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(m==1 || n==1) return 1;
        dp[m-1][n-1]=1;
        for(int j=n-1;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                if(ispos(i-1,j,m,n)) dp[i-1][j]+=dp[i][j];
                if(ispos(i,j-1,m,n)) dp[i][j-1]+=dp[i][j];
            }
        }
        return dp[0][0];
    }
};