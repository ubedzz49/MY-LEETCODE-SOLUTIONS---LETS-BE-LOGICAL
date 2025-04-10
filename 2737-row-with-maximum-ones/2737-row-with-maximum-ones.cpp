class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans=0;
        int mx=0;
        for(int i=0;i<mat.size();i++){
            int s=accumulate(mat[i].begin(),mat[i].end(),0);
            if(s>mx){
                mx=s;
                ans=i;
            }
        }
        return {ans,mx};
    }
};