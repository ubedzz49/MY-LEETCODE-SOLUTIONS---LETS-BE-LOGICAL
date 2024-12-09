class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> dp(nums.size(),make_pair(1,-1));
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i].first<dp[j].first+1){
                        dp[i]=make_pair(dp[j].first+1,j);
                    }
                }
            }
        }
        vector<int> ans;
        int mx=-1;
        int ind=-1;
        for(int i=0;i<dp.size();i++){
            if(dp[i].first>mx){
                mx=dp[i].first;
                ind=i;
            }
        }
        while(ind!=-1){
            ans.push_back(nums[ind]);
            ind=dp[ind].second;
        }
        return ans;
    }
};