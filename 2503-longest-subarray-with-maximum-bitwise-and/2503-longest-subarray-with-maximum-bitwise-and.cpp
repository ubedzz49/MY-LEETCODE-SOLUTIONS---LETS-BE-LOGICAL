class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int ans=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                c++;
                ans=max(ans,c);
            }else{
                c=0;
            }
        }
        return ans;
    }
};