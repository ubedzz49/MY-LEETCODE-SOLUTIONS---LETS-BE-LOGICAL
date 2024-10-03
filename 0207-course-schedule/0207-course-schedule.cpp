class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<pr.size();i++){
            adj[pr[i][1]].push_back(pr[i][0]);
            indegree[pr[i][0]]++;
        }
        queue<int> q;
        vector<int> ts;
       
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            cout<<f;
            q.pop();
            ts.push_back(f);
            for(int i=0;i<adj[f].size();i++){
                indegree[adj[f][i]]--;
                if(indegree[adj[f][i]]==0){
                    q.push(adj[f][i]);
                }
            }
        }
        for(int i=0;i<ts.size();i++){
            cout<<ts[i]<<" ";
        }
        if(ts.size()==n){
            return true;
        }
        return false;
    }
};