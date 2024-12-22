class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-2;i++){
            for(int j=1;j<n-i-1;j++){
                for(int k=j;k<=j+i;k++){
                    dp[j][j+i]=max(dp[j][j+i],nums[j-1]*nums[k]*nums[j+i+1]+dp[j][k-1]+dp[k+1][j+i]);
                }
            }
        }
        return dp[1][n-2];
    }
};