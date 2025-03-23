class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        ways[0] = 1;
        while(!pq.empty()) {
            long long wt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]) {
                long long u = it.first;
                long long w = it.second;
                if(wt + w < dist[u]) {
                    dist[u] = wt + w;
                    ways[u] = ways[node];
                    pq.push({dist[u], u});
                }
                else if (wt + w == dist[u]) {
                    ways[u] = (ways[u] + ways[node]) % 1000000007;
                }
            }
        }
        return ways[n - 1];
    }
};