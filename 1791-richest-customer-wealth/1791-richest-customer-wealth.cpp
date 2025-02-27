class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int ans=0;
        for(auto it:acc) ans=max(ans,accumulate(it.begin(),it.end(),0));
        return ans;
    }
};