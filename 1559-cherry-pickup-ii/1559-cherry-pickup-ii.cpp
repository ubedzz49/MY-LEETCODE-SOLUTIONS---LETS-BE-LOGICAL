class Solution {
public:
bool ispos(int i,int j,int n){
    if(i<n && j<n && i>=0 && j>=0)return true;
    return false;
}
    int cherryPickup(vector<vector<int>>& grid) {
        vector<int> v=grid[grid.size()-1];
        vector<vector<int>> dplast(grid[0].size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i==j){
                    dplast[i][j]=v[i];
                }else{
                    dplast[i][j]=v[i]+v[j];
                }
            }
        }

        for(int k=grid.size()-2;k>=0;k--){
            vector<int> nums=grid[k];
            vector<vector<int>> dpcurr(grid[0].size(),vector<int>(grid[0].size(),0));
            for(int i=0;i<dplast.size();i++){
                for(int j=0;j<dplast.size();j++){
                    if(ispos(i,j,dplast.size())){
                        dpcurr[i][j]=max(dplast[i][j],dpcurr[i][j]);
                    }
                    if(ispos(i+1,j,nums.size())){
                        dpcurr[i][j]=max(dplast[i+1][j],dpcurr[i][j]);
                    }
                    if(ispos(i-1,j,nums.size())){
                        dpcurr[i][j]=max(dplast[i-1][j],dpcurr[i][j]);
                    }
                    if(ispos(i,j+1,nums.size())){
                        dpcurr[i][j]=max(dplast[i][j+1],dpcurr[i][j]);
                    }
                    if(ispos(i+1,j+1,nums.size())){
                        dpcurr[i][j]=max(dplast[i+1][j+1],dpcurr[i][j]);
                    }
                    if(ispos(i-1,j+1,nums.size())){
                        dpcurr[i][j]=max(dplast[i-1][j+1],dpcurr[i][j]);
                    }
                    if(ispos(i,j-1,nums.size())){
                        dpcurr[i][j]=max(dplast[i][j-1],dpcurr[i][j]);
                    }
                    if(ispos(i+1,j-1,nums.size())){
                        dpcurr[i][j]=max(dplast[i+1][j-1],dpcurr[i][j]);
                    }
                    if(ispos(i-1,j-1,nums.size())){
                        dpcurr[i][j]=max(dplast[i-1][j-1],dpcurr[i][j]);
                    }
                    dpcurr[i][j]+=nums[i];
                    if(i!=j) dpcurr[i][j]+=nums[j];
                }
            }
            dplast=dpcurr;
        }
        return dplast[0][dplast[0].size()-1];
    }
};