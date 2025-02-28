class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        vector<pair<int,string>> dp(s2.size()+1,make_pair(0,""));
        for(int i=0;i<s1.size();i++){
            vector<pair<int,string>> dp1(s2.size()+1,make_pair(0,""));
            for(int j=1;j<=s2.size();j++){
                if(s1[i]==s2[j-1]) dp1[j]=make_pair(dp[j-1].first+1,dp[j-1].second+s1[i]);
                else {
                    if(dp1[j-1].first>dp[j].first) dp1[j]=dp1[j-1];
                    else dp1[j]=dp[j];
                }
            }
            dp=dp1;
        }
        string sup=dp[dp.size()-1].second;
        int i=0;
        int j=0;
        string ans="";
        for(auto it:sup){
            while(it!=s1[i]){
                ans.push_back(s1[i]);
                i++;
            }
            while(it!=s2[j]){
                ans.push_back(s2[j]);
                j++;
            }
            ans+=it;
            i++;
            j++;
        }
        while(i<s1.size()){
                ans.push_back(s1[i]);
                i++;
            }
            while(j<s2.size()){
                ans.push_back(s2[j]);
                j++;
            }
        return ans;
    }
};