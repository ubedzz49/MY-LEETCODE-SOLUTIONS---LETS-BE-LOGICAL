class Solution {
public:
void backtrack(vector<vector<int>>& ans,vector<int>& path,vector<int>& nums,int ind){
        ans.push_back(path);
        if(ind==nums.size()) return;
    for(int i=ind;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(ans,path,nums,i+1);
            path.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(ans.begin(),ans.end());
        backtrack(ans,path,nums,0);
        return ans;
    }
};