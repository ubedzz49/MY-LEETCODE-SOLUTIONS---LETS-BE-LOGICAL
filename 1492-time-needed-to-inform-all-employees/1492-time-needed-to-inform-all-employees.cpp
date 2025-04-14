class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<manager.size();i++) mpp[manager[i]].push_back(i);
        int ans=0;
        queue<pair<int,int>> q;
        q.push(make_pair(headID,0));
        while(!q.empty()){
            int node=q.front().first;
            int t=q.front().second;
            ans=max(ans,t);
            int tt=informTime[node];
            q.pop();
            for(auto it:mpp[node]){
                q.push(make_pair(it,t+tt));
            }
        }
        return ans;
    }
};