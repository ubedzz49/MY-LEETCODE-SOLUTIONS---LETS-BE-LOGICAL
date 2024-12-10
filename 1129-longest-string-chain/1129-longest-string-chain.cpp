class Solution {
public:
    static bool comparator(const string w1, const string w2) {
        return w1.size() < w2.size();
    }
    bool isfine(string w1, string w2) {
        if (w1.size() != w2.size() - 1)
            return 0;
        int un = 0;
        int c = 0;
        for (auto it : w2) {
            if (it == w1[c])
                c++;
            else
                un++;
        }
        return un == 1;
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(), 1);
        sort(words.begin(), words.end(), comparator);
        int ans = 1;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isfine(words[j], words[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};

// //DP + LONGEST COMMON SUBSEQUEMNCE CONCEPT SOLUTION BELOW
// //MEMORY LIMIT EXCEEDS AT 76/86
// class Solution {
// public:
// static bool comparator(const string w1,const string w2){
//     return w1.size()<w2.size();
// }
// bool isfine(string w1,string w2){
//     if(w1.size()!=w2.size()-1) return 0;
//     vector<vector<int>> dp(w1.size()+1,vector<int> (w2.size()+1,0));
//     for(int i=1;i<dp.size();i++){
//         for(int j=1;j<dp[0].size();j++){
//             if(w1[i-1]==w2[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
//             else
//             dp[i][j]=max(dp[i][j],max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1])));
//         }
//     }
//     if(dp[dp.size()-1][dp[0].size()-1]==w1.size()) return 1;
//     return 0;
// }
//     int longestStrChain(vector<string>& words) {
//         vector<int> dp(words.size(),1);
//         sort(words.begin(),words.end(),comparator);
//         for(int i=1;i<words.size();i++){
//             for(int j=0;j<i;j++){
//                 if(isfine(words[j],words[i]) && dp[i]<dp[j]+1)dp[i]=dp[j]+1;
//             }
//         }
//         return *max_element(dp.begin(),dp.end());
//     }
// };