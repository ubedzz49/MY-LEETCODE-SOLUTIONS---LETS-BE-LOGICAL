class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum-k)%2!=0) return 0;
        k=(sum-k)/2;
        if(k<0) return 0;
        vector<int> dp(k+1,0);
        dp[0]++;
        if(nums[0]<=k) dp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            vector<int> dp2=dp;
            for(int j=0;j<dp.size();j++){
                if(j+nums[i]>k || dp2[j]==0) continue;
                dp[j+nums[i]]+=dp2[j];
            }
            for(auto it:dp) cout<<it<<" ";
            cout<<endl;
        }
        return dp[k];
    }
};