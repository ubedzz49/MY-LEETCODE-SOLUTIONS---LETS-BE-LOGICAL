class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=0;
        for(auto it:nums){
            ans+=mpp[it];
            mpp[it]++;
        }
        return ans;
    }
};