class Solution {
public:
void backtrack(unordered_set<int>& sett,vector<vector<int>>& ans,vector<int>& path){
    if(sett.size()==0) {
        ans.push_back(path);
        return;
    }
    unordered_set<int> settt=sett;
    for(auto i:settt){
        int it=i;
        path.push_back(it);
        sett.erase(it);
        backtrack(sett,ans,path);
        path.pop_back();
        sett.insert(it);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> sett;
        for(auto it:nums) sett.insert(it);
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(sett,ans,path);
        return ans;
    }
};