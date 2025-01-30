class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> color(n + 1, -1);
        vector<vector<int>>g(n + 1);
        for (vector<int> ed : edges) {
            g[ed[0]].push_back(ed[1]);
            g[ed[1]].push_back(ed[0]);
        }
        for (int i = 1; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!isBipartite(g, i, color))
                    return -1;
            }
        }
        int result = 0;
        vector<int> visit(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (visit[i] != 0) continue;
            int mx = 0;
            vector<int> component_nodes = get_nodes(g, i, visit);
            for (int node: component_nodes) {
                vector<int> distance(n+1, -1);
                int dist = calculateDistance(g, node, distance);
                //cout << node<<" "<< dist<<endl;
                mx = max(mx, dist);
            }
            result += mx;
        }
        return result;
    }
    vector<int> get_nodes(vector<vector<int>>& g, int node, vector<int>& visit) {
        vector<int> result;       
        queue<int>q;
        q.push(node);
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            result.push_back(f);
            for (auto adj: g[f]) {
                if (visit[adj] != 0) 
                    continue;
                q.push(adj);
                visit[adj] = 1;
            }
        }
        return result;
    }
    int calculateDistance(vector<vector<int>>& g, int node, vector<int> dist) {
        vector<int> level_dist;
        int res = 1;
        dist[node] = 1;
        level_dist.push_back(node);
        while(!level_dist.empty()) {
            vector<int> lvl;
            for(int lvl_node : level_dist) {
                for (int adj_node : g[lvl_node]) {
                    if (dist[adj_node] == -1) {
                        dist[adj_node] = dist[lvl_node] + 1;
                        res = max(res, dist[adj_node]);            
                        lvl.push_back(adj_node);
                    }
                }
            }         
            swap(lvl, level_dist);
        }
        return res;
    }
    bool isBipartite(vector<vector<int>>& g, int node, vector<int>& color) {
        bool is_bipartite = true;
        for (int adj_node : g[node]) {
            if (color[adj_node] != -1 && color[adj_node] == color[node])
                return false;
            if (color[adj_node] != -1) 
                continue;
            color[adj_node] = !color[node];
            is_bipartite = is_bipartite && isBipartite(g, adj_node, color);
            if (!is_bipartite)
                return is_bipartite;
        }
        return is_bipartite;
    }
};