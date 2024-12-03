class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v={1};
        ans.push_back(v);
        for(int n=2;n<=numRows;n++){
            vector<int> p(n,0);
            for(int i=0;i<n-1;i++){
                p[i]+=v[i];
                p[i+1]+=v[i];
            }
            ans.push_back(p);
            v=p;
        }
        return ans;
    }
};