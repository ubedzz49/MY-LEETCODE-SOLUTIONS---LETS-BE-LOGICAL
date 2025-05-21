class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        vector<int> rows;
        vector<int> col;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[0].size();j++){
                if(nums[i][j]==0){
                    rows.push_back(i);
                    col.push_back(j);
                }
            }
        }
        rows.erase(unique(rows.begin(),rows.end()),rows.end());
        col.erase(unique(col.begin(),col.end()),col.end());
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<nums[0].size();j++){
                nums[rows[i]][j]=0;
            }
        }
        for(int i=0;i<col.size();i++){
            for(int j=0;j<nums.size();j++){
                nums[j][col[i]]=0;
            }
        }
    }
};