class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {

        vector<int> dp(sum+1,INT_MAX);
        dp[0]=0;
        for(auto c:coins){
            for(int i=0;i<=sum;i++){
                if(i<=sum-c && dp[i]!=INT_MAX) dp[i+c]=min(dp[i+c],dp[i]+1);
            }
        }
        if(dp[sum]==INT_MAX) return -1;
        return dp[sum];
    }
};