class Solution {
public:
void backtrack(int it,vector<vector<int>>& ans,vector<int>& curr,vector<int>& can,int target){
    if(target<0) return;
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(it>=can.size()) return;
    curr.push_back(can[it]);
    backtrack(it+1,ans,curr,can,target-can[it]);
    curr.pop_back();
    for(int i=it+1;i<can.size();i++){
        if(can[i]!=can[i-1]){
            curr.push_back(can[i]);
            backtrack(i+1,ans,curr,can,target-can[i]);
            curr.pop_back();
        }
    }
    return ;
}
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(can.begin(),can.end());
        backtrack(0,ans,curr,can,target);
        return ans;
    }
};