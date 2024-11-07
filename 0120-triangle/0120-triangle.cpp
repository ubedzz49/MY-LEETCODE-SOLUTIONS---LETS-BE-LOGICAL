class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        vector<vector<int>> dp(nums.size());
        for(int i=0;i<dp.size();i++){
            dp[i]=vector<int>(nums[i].size(),INT_MAX);
        }
        dp[dp.size()-1]=nums[nums.size()-1];
        for(int i=dp.size()-2;i>=0;i--){
            for(int j=0;j<dp[i].size();j++){
                dp[i][j]=nums[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};