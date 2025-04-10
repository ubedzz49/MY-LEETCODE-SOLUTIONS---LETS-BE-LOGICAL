class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int mx=0;
        for(int i=0;i<mat.size();i++){
            int s=accumulate(mat[i].begin(),mat[i].end(),0);
            if(s==mx) ans.push_back(i);
            else if(s>mx){
                mx=s;
                ans={i};
            }
        }
        return {ans[0],mx};
    }
};