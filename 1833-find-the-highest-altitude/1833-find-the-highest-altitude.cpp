class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};