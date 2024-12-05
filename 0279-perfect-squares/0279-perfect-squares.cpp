class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1,-1);
       dp[0]=0;
       dp[1]=1;
        for(int i=1;i<n+1;i++){
            if(sqrt(i)==floor(sqrt(i))){
                dp[i]=1;
            }
            if(dp[i]==-1) continue;
            else{
                for(int j=0;j<=i && j+i<=n;j++){
                    if(dp[j]==-1) continue;
                    if(dp[i+j]==-1) {dp[j+i]=dp[j]+dp[i];}
                    else dp[j+i]=min(dp[j+i],dp[j]+dp[i]);
                }
            }
        }
        return dp[n];
    }
};