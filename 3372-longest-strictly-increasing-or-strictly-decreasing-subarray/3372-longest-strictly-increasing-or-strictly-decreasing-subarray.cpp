class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) c++;
            else{
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        c=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]) c++;
            else{
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
    }
};