class Solution {
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int target) {
                vector<pair<int,double>> adj[n];

                        for(int i=0;i<edges.size();i++){
                                    adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
                                                adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
                                                        }

                                                                vector<double> dist(n,0);
                                                                        dist[src] = 1;
                                                                                //  cout<<dist[src];
                                                                                        priority_queue<pair<double,int>>pq;
                                                                                                pq.push({1,src});

                                                                                                        while(!pq.empty()){
                                                                                                                    double dis = pq.top().first;
                                                                                                                                int node = pq.top().second;
                                                                                                                                            pq.pop();
                                                                                                                                                        for(auto adjnode : adj[node]){
                                                                                                                                                                        if(dis*adjnode.second > dist[adjnode.first]){
                                                                                                                                                                                            dist[adjnode.first] = dis*adjnode.second;
                                                                                                                                                                                                                pq.push({dist[adjnode.first],adjnode.first});
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                            // cout<<dist[src];
                                                                                                                                                                                                                                                                    return dist[target];
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                        };