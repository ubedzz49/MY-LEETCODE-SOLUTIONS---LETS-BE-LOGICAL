class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        //TABULATION
        vector<vector<int>> dp(nums.size(),vector<int>(nums[0].size(),INT_MAX));
        dp[dp.size()-1]=nums[nums.size()-1];
        for(int i=dp.size()-2;i>=0;i--){
            for(int j=0;j<dp[0].size();j++){
                if(j>0) dp[i][j]=min(dp[i][j],dp[i+1][j-1]+nums[i][j]);
                if(j<dp[0].size()-1) dp[i][j]=min(dp[i][j],dp[i+1][j+1]+nums[i][j]);
                dp[i][j]=min(dp[i][j],dp[i+1][j]+nums[i][j]);
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};