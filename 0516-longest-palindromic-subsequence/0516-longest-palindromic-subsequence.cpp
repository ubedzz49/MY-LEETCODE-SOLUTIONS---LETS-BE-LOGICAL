class Solution {
public:
    int longestPalindromeSubseq(string s2) {
        string s1=s2;
        reverse(s1.begin(),s1.end());
        int m=s1.size();
        int n=s2.size();
        int ans=0;
        vector<int> dp(m+1,0);
        for(int i=1;i<=m;i++){
            vector<int> dp2(m+1,0);
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp2[j]=1+dp[j-1];
                }else{
                    dp2[j]=max(dp[j],dp2[j-1]);
                }
            }
            dp=dp2;
        }
        return dp[dp.size()-1];
    }
};