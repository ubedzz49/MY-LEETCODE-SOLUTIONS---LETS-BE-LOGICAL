class Solution {
public:
    void bfs(int st, vector<int>& edges, vector<int>& dist){
        int n = edges.size();
        queue<int> q;
        q.push(st);
        vector<bool> vis(n, false);
        vis[st] = true;
        dist[st] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int next = edges[curr];
            if(next!=-1 && !vis[next]){
                dist[next] = dist[curr]+1;
                vis[next] = true;
                q.push(next);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int minD = INT_MAX;
        int ans = -1;
        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int d = max(dist1[i] , dist2[i]);
                if(d<minD){
                    minD = d;
                    ans = i;
                }
            }
        }

        return ans;
    }
};