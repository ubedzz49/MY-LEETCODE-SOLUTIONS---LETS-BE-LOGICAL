class Solution {
public:
    int change(int sum, vector<int>& coins) {
        //SPACE OPTIMISED APPROACT USING ONLY ONE VECTOR
        vector< unsigned long long> dp(sum+1,0);
        dp[0]=1;
        for(auto c:coins){
            for(int i=0;i<=sum;i++){
                if(i+c<=sum) dp[i+c]+=dp[i];
            }
        }
        return dp[sum];
    }
};