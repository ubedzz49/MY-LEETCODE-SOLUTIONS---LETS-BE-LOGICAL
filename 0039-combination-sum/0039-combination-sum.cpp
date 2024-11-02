class Solution {
public:
void rec(vector<vector<int>>& ans,vector<int> curr,vector<int>& can,int& t,int sum,int i){
    if(sum==t){ans.push_back(curr);return;}
    if(sum>t) return;
    while(sum<=t && i<can.size()){
        rec(ans,curr,can,t,sum,i+1);
        sum+=can[i];
        curr.push_back(can[i]);
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        rec(ans,curr,can,t,0,0);
        return ans;
    }
};