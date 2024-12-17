class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
       cuts.push_back(0);
    cuts.push_back(n);
    int c=cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c,vector<int>(c,0));
    for(int k=2;k<c;k++){
        for(int i=0;i<c-k;i++){
            dp[i][i+k]=INT_MAX;
            for(int j=i+1;j<i+k;j++){
                dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j][i+k]+cuts[i+k]-cuts[i]);
            }
        }
    }
    return dp[0][c-1];
    }
};