class Solution {
public:
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int m=s.size();
        vector<int> dp(m+1,0);
        for(int i=1;i<=m;i++){
            vector<int> dp2(m+1,0);
            for(int j=1;j<=m;j++){
                if(s[i-1]==r[j-1]){
                    dp2[j]=1+dp[j-1];
                }else{
                    dp2[j]=max(dp[j],dp2[j-1]);
                }
            }
            dp=dp2;
        }
        return m-dp[m];
    }
};