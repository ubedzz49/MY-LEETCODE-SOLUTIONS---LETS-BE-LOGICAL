//MEMOIZATION
// class Solution {
// public:
// int dy(vector<int>& dp,int n){
//     if(n<=1) return 1;
//     if(dp[n]==-1){
//         dp[n]=dy(dp,n-1)+dy(dp,n-2);
//     }
//     return dp[n];
// }
//     int climbStairs(int n) {
//         if(n<=1) return 1;
//         vector<int> dp(n+1,-1);
//         dp[0]=1;
//         dp[1]=1;
//         return dy(dp,n);
//     }
// };



//----------------------------------


//TABULATION 
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int a=1;
        int b=1;
        for(int i=2;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
            if(i==n) return c;
        }
        return 0;
    }
};