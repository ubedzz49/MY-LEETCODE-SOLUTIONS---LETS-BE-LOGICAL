class Solution {
public:
// //MEMOIZATION
// int memo(vector<vector<int>>& dp,vector<vector<int>>& nums,int i,int j){
//     if(i==nums.size()-1 && j==nums[0].size()-1) return nums[i][j];
//     int ans=INT_MAX;
//     if(i+1<nums.size()){
//         if(dp[i+1][j]==-1) memo(dp,nums,i+1,j);
//         ans=dp[i+1][j];
//     }
//     if(j+1<nums[0].size()){
//         if(dp[i][j+1]==-1) memo(dp,nums,i,j+1);
//         ans=min(ans,dp[i][j+1]);
//     }
//     return dp[i][j]=ans+nums[i][j];
// }

    int minPathSum(vector<vector<int>>& nums) {
        // //MEMOIZATION
        // vector<vector<int>> dp(nums.size(),vector<int>(nums[0].size(),-1));
        // dp[nums.size()-1][nums[0].size()-1]=nums[nums.size()-1][nums[0].size()-1];
        // return memo(dp,nums,0,0);

        //TABULATION
        vector<vector<int>> dp(nums.size(),vector<int>(nums[0].size(),INT_MAX));
        dp[nums.size()-1][nums[0].size()-1]=nums[nums.size()-1][nums[0].size()-1];
        //cout<<dp[nums.size()-1][nums[0].size()-1];
        for(int j=nums[0].size()-1;j>=0;j--){
            for(int i=nums.size()-1;i>=0;i--){
                 if(i>0) dp[i-1][j]=min(dp[i-1][j],nums[i-1][j]+dp[i][j]);
                 if(j>0) dp[i][j-1]=min(dp[i][j-1],nums[i][j-1]+dp[i][j]);
            }
        }
        return dp[0][0];
    }
};