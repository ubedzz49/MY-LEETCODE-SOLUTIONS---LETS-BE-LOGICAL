class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            long long take = questions[i][0];
            long long nottake = dp[i + 1];
            if (i + questions[i][1] + 1 <= n) {
                take += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(take, nottake);
        }
        return dp[0];
    }
};