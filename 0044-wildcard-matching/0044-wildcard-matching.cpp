class Solution {
public:
    bool isMatch(string text, string pattern) {
        // vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,0));
        // dp[0][0]=1;
        // for(int i=0;i<p.size();i++) {
        //     if(p[i]=='*') dp[0][i+1]=1;
        //     else break;
        // }
        // for(int i=1;i<=s.size();i++){
        //     for(int j=1;j<=p.size();j++){
        //         if(p[j-1]=='?' || p[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1];
        //         else if(p[j-1]=='*') dp[i][j]=(dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]);
        //     }
        // }
        // return dp[s.size()][p.size()];
        vector<bool> dp(pattern.size()+1,0);
   for (int i = 0; i < pattern.size(); i++) {
     if (pattern[i] == '*') dp[i + 1] = 1;
     else break;
   }
   dp[0]=1;
      for(int i=0;i<text.size();i++){
         vector<bool> dp2=dp;
         dp[0]=0;
         for(int j=1;j<dp.size();j++){
            if(pattern[j-1]=='?' || pattern[j-1]==text[i]) dp[j]=dp2[j-1];
            else if(pattern[j-1]=='*') dp[j]=dp[j-1]||dp2[j-1]||dp2[j];
            else dp[j]=false;
         }
      }
   return dp[dp.size()-1];
    }
};