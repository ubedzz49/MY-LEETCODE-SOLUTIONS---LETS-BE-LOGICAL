class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            vector<int> dp2=dp;
            dp2[0]=min(dp2[0],nums[i]);
            for(int j=0;j<nums.size()-1;j++){
                if(nums[i]>dp[j]) dp2[j+1]=min(dp2[j+1],nums[i]);
            }
            dp=dp2;
        }
        for(int i=dp.size()-1;i>=0;i--){
            if(dp[i]!=INT_MAX) return i+1;
        }
        return 0;
    }
};