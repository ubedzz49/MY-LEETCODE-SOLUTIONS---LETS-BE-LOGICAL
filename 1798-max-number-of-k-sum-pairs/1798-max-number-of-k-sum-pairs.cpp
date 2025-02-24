class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        int ans=0;
        for(auto it:nums){
            if(it*2==k){
                ans+=(mpp[it]/2);
                mpp[it]=0;
                continue;
            }
            int a=min(mpp[k-it],mpp[it]);
            ans+=a;
            mpp[k-it]-=a;
            mpp[it]-=a;
        }
        return ans;
    }
};