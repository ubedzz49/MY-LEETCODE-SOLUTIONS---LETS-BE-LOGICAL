class Solution {
public:
    int minDistance(string word1, string word2) {
        //OPTIMIZED APPROACH USING 2 VECTORS
        //MOST OPTIMIZED APPROACH USING ONE VECTOR AT CODE360
        vector<int> dp(word2.size()+1,0);
        for(int i=0;i<dp.size();i++) dp[i]=i;
        for(int i=1;i<word1.size()+1;i++){
            vector<int> dp2=dp;
            dp2[0]++;
            for(int j=1;j<word2.size()+1;j++){
                if(word1[i-1]==word2[j-1]) dp2[j]=dp[j-1];
                else dp2[j]=min(dp[j-1],min(dp2[j-1],dp[j]))+1;
            }
            dp=dp2;
        }
        return dp[word2.size()];
    }
};