class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        //SPACE OPTIMIZED TABULATION IS BELOW
        //TABULATION WITHOUT SPACE OPTIMIZATION IS AT CODE 360 LONGEST COMMON SUBSEQUENCE
        int m=text2.size();
        int n=text1.size();
        vector<int> dp(m+1,0);

        for(int i=0;i<n;i++){
            vector<int> dp2(m+1,0);
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp2[j+1]=1+dp[j];
                }else{
                    dp2[j+1]=0+max(dp2[j],dp[j+1]);
                }
            }
            dp=dp2;
        }
        return *max_element(dp.begin(),dp.end());
    }
};