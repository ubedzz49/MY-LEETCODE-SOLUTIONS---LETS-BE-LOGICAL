class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int tp=0;
        unordered_map<long long,long long> mpp;
        for(int i=nums.size()-1;i>=0;i--){
            mpp[nums[i]-i]++;
            ans+=mpp[nums[i]-i]-1;
        }
        cout<<ans;
        return ((nums.size()*(nums.size()-1))/2)-ans;
    }
};