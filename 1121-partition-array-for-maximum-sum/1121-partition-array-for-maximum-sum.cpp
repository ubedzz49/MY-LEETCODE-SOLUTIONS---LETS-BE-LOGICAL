class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<nums.size();i++){
            int maxval=0;
            for(int j=i;j>i-k && j>=0;j--){
                maxval=max(maxval,nums[j]);
                if(j!=0) dp[i]=max(dp[i],dp[j-1]+(maxval*(i-j+1)));
                else dp[i]=max(dp[i],maxval*(i-j+1));
            }
        }
        return dp[n-1];
    }
};