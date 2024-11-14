class Solution {
public:
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int> dp2(n+1,0);
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp2[j]=dp[j-1]+1;
                }else{
                    dp2[j]=max(dp[j],dp2[j-1]);
                }
            }
            dp=dp2;
        }
        return m+n-dp[n]*2;
    }
};