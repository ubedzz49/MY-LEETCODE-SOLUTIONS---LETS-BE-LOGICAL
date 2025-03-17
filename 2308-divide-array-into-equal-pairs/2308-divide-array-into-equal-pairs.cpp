class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        for(auto it:nums) mpp[it]=!mpp[it];
        for(auto it:mpp) if(it.second==1) return 0;
        return 1;
    }
};