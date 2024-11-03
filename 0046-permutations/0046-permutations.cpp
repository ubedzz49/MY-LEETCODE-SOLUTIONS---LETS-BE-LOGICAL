class Solution {
public:
// void backtrack(unordered_set<int>& sett,vector<vector<int>>& ans,vector<int>& path){
//     if(sett.size()==0) {
//         ans.push_back(path);
//         return;
//     }
//     unordered_set<int> settt=sett;
//     for(auto i:settt){
//         int it=i;
//         path.push_back(it);
//         sett.erase(it);
//         backtrack(sett,ans,path);
//         path.pop_back();
//         sett.insert(it);
//     }
// }

//OPTIMAL SOLUTION
void backtrack(vector<vector<int>>& ans,vector<int>& path,vector<int>& nums,vector<bool>& visited){
    if(path.size()==nums.size()){
        ans.push_back(path);
        return;
    }
    for(int i=0;i<visited.size();i++){
        if(!visited[i]){
            visited[i]=1;
            path.push_back(nums[i]);
            backtrack(ans,path,nums,visited);
            path.pop_back();
            visited[i]=0;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        // unordered_set<int> sett;
        // for(auto it:nums) sett.insert(it);
        // vector<vector<int>> ans;
        // vector<int> path;
        // backtrack(sett,ans,path);
        // return ans;

        //OPTIMAL SOLUTION
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> visited(nums.size(),0);
        backtrack(ans,path,nums,visited);
        return ans;
    }
};