class Solution {
public:
int dy(vector<int>& dp,int n){
    if(n<=1) return 1;
    if(dp[n]==-1){
        dp[n]=dy(dp,n-1)+dy(dp,n-2);
    }
    return dp[n];
}
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return dy(dp,n);
    }
};