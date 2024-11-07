class Solution {
public:
bool ispos(int i,int j,vector<vector<int>>& nums){
    if(i<nums.size() && i>=0 && j<nums[0].size() && j>=0 && nums[i][j]==0) return true;
    return false;
}
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int r=nums.size();
        int c=nums[0].size();
        vector<vector<long long>> dp(r,vector<long long>(c,0));
        if(nums[r-1][c-1]==0) dp[r-1][c-1]=1;
        else{return 0;}
        for(int j=c-1;j>=0;j--){
            for(int i=r-1;i>=0;i--){
                if(ispos(i-1,j,nums)) dp[i-1][j]+=dp[i][j];
                if(ispos(i,j-1,nums)) dp[i][j-1]+=dp[i][j];
            }
        }
        return dp[0][0];
    }
};