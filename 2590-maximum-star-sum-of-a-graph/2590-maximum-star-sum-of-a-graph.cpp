class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size());
        for(auto i:edges){
            adj[i[0]].push_back(vals[i[1]]);
            adj[i[1]].push_back(vals[i[0]]);
        }
        int kk=0;
        for(auto i:adj){
            vector<int> it=i;
            sort(it.begin(),it.end());
            reverse(it.begin(),it.end());
            adj[kk]=it;
            kk++;
        }
        int mx=INT_MIN;
        for(int i=0;i<vals.size();i++){
            int sum=vals[i];
            mx=max(mx,sum);
            for(int j=0;j<k && j<adj[i].size();j++){
                sum+=adj[i][j];
                mx=max(mx,sum);
            }
        }
        return mx;
    }
};