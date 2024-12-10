class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        	vector<int> dp(n,0);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(nums[i]>nums[j] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
		}
	}
	int ans=0;
	vector<int> dp2(n,0);
	for(int i=nums.size()-1;i>=0;i--){
		for(int j=i+1;j<nums.size();j++){
            if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1) {
                dp2[i] = dp2[j] + 1;
            }
        }
	}
	for(int i=1;i<n-1;i++){
        if(dp[i]==0 || dp2[i]==0) continue;
		ans=max(ans,dp[i]+dp2[i]+1);
	}
	return nums.size()-ans;
    }
};