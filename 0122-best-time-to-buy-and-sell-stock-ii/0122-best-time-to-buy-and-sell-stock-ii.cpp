class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> dp(prices.size());
        dp[0]=make_pair(0,-prices[0]);
        for(int i=1;i<prices.size();i++){
            dp[i].first=max(dp[i-1].first,dp[i-1].second+prices[i]);
            dp[i].second=max(dp[i-1].second,dp[i-1].first-prices[i]);
        }
        return max(dp[dp.size()-1].first,dp[dp.size()-1].second);
    }
};