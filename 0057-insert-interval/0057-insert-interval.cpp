class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newint) {
           auto it = lower_bound(ints.begin(), ints.end(), newint, 
           [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];});
            ints.insert(it, newint);
        int st=ints[0][0];
        int end=ints[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<ints.size();i++){
            int s=ints[i][0];
            int e=ints[i][1];
            if(s<=end) end=max(e,end);
            else{
                ans.push_back({st,end});
                st=s;
                end=e;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};