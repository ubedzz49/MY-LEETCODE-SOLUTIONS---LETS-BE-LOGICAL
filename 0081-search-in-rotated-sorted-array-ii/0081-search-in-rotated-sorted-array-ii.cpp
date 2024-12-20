class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_map<int,bool> mpp;
        for(auto it:nums) mpp[it]=1;
        return mpp[target];
    }
};