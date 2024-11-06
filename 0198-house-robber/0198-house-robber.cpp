class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev2=nums[0];
        int prev=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            int curr=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};