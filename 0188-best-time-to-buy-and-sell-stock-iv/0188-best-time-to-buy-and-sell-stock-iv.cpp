class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k,vector<int>(2,INT_MIN));
        dp[0][0]=-prices[0];
        for(auto it:prices){
            dp[0][0]=max(dp[0][0],-it);
            dp[0][1]=max(0,dp[0][1]);
            dp[0][1]=max(dp[0][1],dp[0][0]+it);
            cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
            for(int i=1;i<k;i++){
                dp[i][0]=max(dp[i][0],dp[i-1][1]-it);
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
                dp[i][1]=max(dp[i][1],dp[i][0]+it);
                cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            }
            cout<<"----"<<endl;
        }
        for(auto it:dp) cout<<it[0]<<" "<<it[1]<<"  ";
        return dp[k-1][1];
    }
};