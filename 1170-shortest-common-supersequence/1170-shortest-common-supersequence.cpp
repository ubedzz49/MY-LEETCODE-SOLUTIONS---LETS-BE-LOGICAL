class Solution {
public:


string shortestCommonSupersequence(string s1, string s2) {


        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";

        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){ ans+=s1[i-1]; i--; j--;}
            else if(dp[i][j-1]>dp[i-1][j]) j--;
            else i--;
        }
        reverse(ans.begin(),ans.end());
        string fans="";
        int i1=0;
        int i2=0;
        for(auto c:ans){
            for(int i=i1;i<s1.size();i++){
                if(s1[i]==c){
                    i1=i+1;
                    break;
                }
                fans+=s1[i];
            }
            for(int i=i2;i<s2.size();i++){
                if(s2[i]==c){
                    i2=i+1;
                    break;
                }
                fans+=s2[i];
            }
            fans+=c;
        }
        for(int i=i1;i<s1.size();i++) fans+=s1[i];
        for(int i=i2;i<s2.size();i++) fans+=s2[i];
        return fans;
    }
};