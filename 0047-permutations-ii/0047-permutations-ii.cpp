class Solution {
public:
void backtrack(vector<vector<int>>& ans,vector<int>& nums,vector<bool>& visited,vector<int>& path,int& s){
    if(path.size()==s){
        ans.push_back(path);
        return;
    }
    vector<int> num;
    for(int i=0;i<visited.size();i++){
        if(!visited[i]) num.push_back(nums[i]);
    }
    vector<bool> visitedd(num.size(),0);
    for(int i=0;i<num.size();i++){
        if(i==0 || num[i]!=num[i-1]){
            visitedd[i]=1;
            path.push_back(num[i]);
            backtrack(ans,num,visitedd,path,s);
            visitedd[i]=0;
            path.pop_back();
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(),0);
        vector<int> path;
        int s=nums.size();
        backtrack(ans,nums,visited,path,s);
        return ans;
    }
};