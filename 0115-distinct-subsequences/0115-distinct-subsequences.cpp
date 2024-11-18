class Solution {
public:
    int numDistinct(string str, string sub) {
        vector<vector<int>> dp(str.size()+1,vector<int>(sub.size()+1,0));
        long long mod=1e9;
	dp[0][0]=1;
	for(int i=1;i<=str.size();i++){
		dp[i][0]=dp[i-1][0];
		for(int j=1;j<=sub.size();j++){
			dp[i][j]=dp[i-1][j];
			if(str[i-1]==sub[j-1]){
				dp[i][j]+=(dp[i-1][j-1]%mod);
			}
		}
	}
	return dp[dp.size()-1][dp[0].size()-1];
    }
};