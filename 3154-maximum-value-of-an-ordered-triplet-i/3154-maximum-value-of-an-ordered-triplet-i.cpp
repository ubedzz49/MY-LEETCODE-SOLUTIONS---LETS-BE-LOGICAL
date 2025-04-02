class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> suf(nums.size(),-1);
        vector<long long> pre(nums.size(),-1);
        vector<long long> sufmin(nums.size(),-1);
        vector<long long> premin(nums.size(),-1);
        int mx=nums[0];
        int mn=nums[0];
        for(int i=0;i<nums.size();i++){
            pre[i]=mx;
            premin[i]=mn;
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        mx=nums[nums.size()-1];
        mn=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            suf[i]=mx;
            sufmin[i]=mn;
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }

        long long ans=0;
        for(int i=1;i<nums.size()-1;i++){
            ans=max(ans,((pre[i]-nums[i])*suf[i]));
            ans=max(ans,(premin[i]-nums[i])*suf[i]);
            ans=max(ans,(pre[i]-nums[i])*sufmin[i]);
            ans=max(ans,(premin[i]-nums[i])*sufmin[i]);
        }
        return ans;
    }
};