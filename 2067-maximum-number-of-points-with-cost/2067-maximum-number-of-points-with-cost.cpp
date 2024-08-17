class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
         int m = points.size();
        int n = points[0].size();
        
        // Initialize dp with the first row values
        vector<long long> dp(points[0].begin(), points[0].end());
        
        // Iterate over each row from the second row
        for (int i = 1; i < m; ++i) {
            vector<long long> new_dp(n, 0);
            
            // Compute leftMax and rightMax
            vector<long long> leftMax(n), rightMax(n);
            leftMax[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1], dp[j] + j);
            }
            rightMax[n - 1] = dp[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1], dp[j] - j);
            }
            
            // Calculate the new dp values for the current row
            for (int j = 0; j < n; ++j) {
                new_dp[j] = max(leftMax[j] - j, rightMax[j] + j) + points[i][j];
            }
            
            // Update dp to the current row's values
            dp = new_dp;
        }
        
        // The answer will be the maximum value in dp after the last row
        return *max_element(dp.begin(), dp.end());
    }
};