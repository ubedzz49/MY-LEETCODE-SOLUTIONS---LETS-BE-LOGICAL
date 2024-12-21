class Solution {
public:
    int ans = 0;

    long dfs(int i, vector<vector<int>>& adj, vector<int>& vis,vector<int>& val, int k) {
        vis[i] = 1;

        long sum = 0;
        for(auto node : adj[i]) {
            if(!vis[node]) {
                sum += dfs(node, adj, vis, val, k);
            }
        }

        sum += val[i];
        if(sum%k == 0) {
            ans++;
            return 0;
        }
        
        return sum;
    }


    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(0, adj, vis, values, k);

        return ans;
    }
};