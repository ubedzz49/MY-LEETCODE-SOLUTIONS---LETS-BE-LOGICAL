class Solution {
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n = move.size();
        int m = move[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0, 0});
        dp[0][0][0] = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, i, j, b] = pq.top();
            pq.pop();

            if (time > dp[i][j][b]) continue;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                int nb = 1 - b;

                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int cost = (b ? 2 : 1);
                    int waitTime = max(time + cost, move[ni][nj] + cost);
                    if (dp[ni][nj][nb] > waitTime) {
                        dp[ni][nj][nb] = waitTime;
                        pq.push({waitTime, ni, nj, nb});
                    }
                }
            }
        }

        return min(dp[n-1][m-1][0], dp[n-1][m-1][1]);
    }
};
