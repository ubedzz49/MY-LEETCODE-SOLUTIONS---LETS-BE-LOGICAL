class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i:pr){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            ans.push_back(f);
            q.pop();
            for(auto i:adj[f]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }
        return {};
    }
};