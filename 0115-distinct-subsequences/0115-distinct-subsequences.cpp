class Solution {
public:
    int numDistinct(string str, string sub) {
    // //TABULATION WITHOUT MEMORY OPTIMIZATION
    // vector<vector<int>> dp(str.size()+1,vector<int>(sub.size()+1,0));
    // long long mod=1e9+7;
	// dp[0][0]=1;
	// for(int i=1;i<=str.size();i++){
	// 	dp[i][0]=dp[i-1][0];
	// 	for(int j=1;j<=sub.size();j++){
	// 		dp[i][j]=dp[i-1][j];
	// 		if(str[i-1]==sub[j-1]){
	// 			dp[i][j]+=(dp[i-1][j-1]%mod);
	// 		}
	// 	}
	// }
	// return dp[dp.size()-1][dp[0].size()-1];

    //SPACE OPTIMIZED TABULATION
    long long mod=1e9+7;
    vector<int> dp(sub.size()+1,0);
    dp[0]=1;
    for(int i=1;i<=str.size();i++){
        vector<int> dp1=dp;
        for(int j=1;j<=sub.size();j++){
            if(str[i-1]==sub[j-1]){
                dp1[j]+=dp[j-1]%mod;
            }
        }
        dp=dp1;
    }
    return dp[dp.size()-1];
    }
};