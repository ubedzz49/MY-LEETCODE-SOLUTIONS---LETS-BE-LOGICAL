class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n,0);
        for(auto it:edges){
            indegrees[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<indegrees.size();i++){
            if(indegrees[i]==0) q.push(i);
        }
        if(q.size()!=1) return -1;
        int ans=q.front();
        return ans;
    }
};