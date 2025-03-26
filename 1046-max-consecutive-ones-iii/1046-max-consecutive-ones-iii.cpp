class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int o=0;
        int s=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)o++;
            if(o>k){
                o--;
                while(nums[s]!=0) s++;
                s++;
            }
            ans=max(ans,i-s+1);
        }
        return ans;
    }
};