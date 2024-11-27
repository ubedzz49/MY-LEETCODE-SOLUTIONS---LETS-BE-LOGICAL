class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> sd;
        vector<int> ans;
        vector<vector<int>> adjl(n);
        for(int i=0;i<n-1;i++)adjl[i].push_back(i+1);
        for(int i=0;i<n;i++) sd.push_back(i);
        for(auto it:queries){
            adjl[it[0]].push_back(it[1]);
            for(int i=it[0];i<n;i++){
                for(auto jt:adjl[i]){
                    sd[jt]=min(sd[jt],sd[i]+1);
                }
                
            }
            ans.push_back(sd[sd.size()-1]);
        }
        return ans;
    }
};