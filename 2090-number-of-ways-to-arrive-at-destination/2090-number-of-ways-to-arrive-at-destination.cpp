class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n); // adjacency list with {neighbor, distance}
        
        // Building the graph
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Distances and path counts
        vector<long long> dist(n, LLONG_MAX); // shortest distance to each node
        vector<int> ways(n, 0);               // number of ways to reach each node
        
        dist[0] = 0;  // starting node has 0 distance
        ways[0] = 1;  // there's 1 way to reach the starting node
        
        pq.push({0, 0}); // {distance, node}
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // If we found a longer distance to `u`, skip processing
            if (d > dist[u]) continue;
            
            for (auto& [v, time] : adj[u]) {
                long long newDist = d + time;
                
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
