class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(),make_pair(1,1));
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j].first+1==dp[i].first){
                        dp[i].second+=dp[j].second;
                    }
                    if(dp[j].first+1>dp[i].first) {
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                }
            }
        }
        int mx=0;
        int ln=0;
        for(auto it:dp){
            mx=max(mx,it.first);
        }
        for(auto it:dp){
            if(it.first==mx) ln+=it.second;
        }
        return ln;
    }
};