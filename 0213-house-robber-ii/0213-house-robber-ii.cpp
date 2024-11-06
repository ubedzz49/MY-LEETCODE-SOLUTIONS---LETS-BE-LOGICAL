class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=2) return *max_element(nums.begin(),nums.end());
        int prev=max(nums[0],nums[1]);
        int prev2=nums[0];
        for(int i=2;i<nums.size();i++){
            int curr=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }
        int a=prev2;
        reverse(nums.begin(),nums.end());
        nums.pop_back();
        reverse(nums.begin(),nums.end());
        prev=max(nums[0],nums[1]);
        prev2=nums[0];
        for(int i=2;i<nums.size();i++){
            int curr=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }
        return max(a,prev);
    }
};