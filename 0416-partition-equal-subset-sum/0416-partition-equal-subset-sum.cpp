class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        sum/=2;
        vector<bool> dp(sum+1,0);
        dp[0]=1;
        for(auto it:nums){
            vector<bool> dp2=dp;
            for(int i=0;i<dp2.size();i++){
                if(i+it<=sum && dp2[i]==1){ dp[i+it]=1;}
                
            }
        }
        return dp[sum];
    }
};