class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj1={};
        vector<vector<pair<int,int>>> adj(n,adj1);
        for(auto i:roads){
            adj[i[0]].push_back(make_pair(i[1],i[2]));
            adj[i[1]].push_back(make_pair(i[0],i[2]));
        }
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        vector<long long> sp(n,LLONG_MAX);
        sp[0]=0;
        vector<int> spw(n,0);
        spw[0]=1;
        pq.push({0,0});
        const int MOD = 1e9 + 7;  // Define the modulo constant

        while(!pq.empty()){
            long long dist=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();
            for(auto i:adj[node]){
                long long newDist = dist + i.second;
                if(newDist == sp[i.first]){
                    spw[i.first] = (spw[i.first] + spw[node]) % MOD;  // Apply modulo
                }
                if(newDist < sp[i.first]){
                    sp[i.first] = newDist;
                    pq.push({sp[i.first], i.first});
                    spw[i.first] = spw[node] % MOD;  // Apply modulo
                }
            }
        }

        return spw[n-1] % MOD;  // Apply modulo to the result
    }
};
