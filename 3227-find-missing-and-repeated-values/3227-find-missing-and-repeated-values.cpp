class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> mpp(n*n+1,0);
        for(auto it:grid) for(auto i:it) mpp[i]++;
        int c,d;
        for(int i=1;i<=n*n;i++){
            if(mpp[i]==0){
                c=i;
            }
            if(mpp[i]==2) d=i;
        }
        return {d,c};
    }
};