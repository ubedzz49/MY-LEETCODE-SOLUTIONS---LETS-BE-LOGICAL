class Solution {
public:
void fn(vector<vector<int>>& ans,vector<int>& a,int i,int n,int k){
    if(i==11) return;
    if(a.size()==k){
        if(accumulate(a.begin(),a.end(),0)==n) ans.push_back(a);
        return;
    }
    a.push_back(i);
    i++;
    fn(ans,a,i,n,k);
    a.pop_back();
    fn(ans,a,i,n,k);
    i--;
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans={};
        vector<int> a={};
        int i=1;
        fn(ans,a,i,n,k);
        return ans;
    }
};