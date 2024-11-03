class Solution {
public:
void backtrack(vector<vector<int>>& ans,vector<int>& path,vector<int>& nums,int in){
    ans.push_back(path);
    if(in==nums.size()){
        return;
    }
    path.push_back(nums[in]);
    backtrack(ans,path,nums,in+1);
    path.pop_back();
    //backtrack(ans,path,nums,in+1);
    for(int i=in+1;i<nums.size();i++){
        
        if(nums[i]!=nums[i-1]){
            path.push_back(nums[i]);
            backtrack(ans,path,nums,i+1);
            path.pop_back();
            //backtrack(ans,path,nums,i+1);
        }
    }
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        int i=0;
        backtrack(ans,path,nums,i);
        return ans;
    }
};