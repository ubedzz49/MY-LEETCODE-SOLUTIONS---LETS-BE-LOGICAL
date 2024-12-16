class Solution {
public:
int lcs(string w1,string w2){
    vector<vector<int>> dp(w1.size()+1,vector<int> (w2.size()+1,0));
    for(int i=1;i<=w1.size();i++){
        for(int j=1;j<=w2.size();j++){
            if(w1[i-1]==w2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}
    int longestPalindromeSubseq(string s) {
        string t=s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
    }
};
