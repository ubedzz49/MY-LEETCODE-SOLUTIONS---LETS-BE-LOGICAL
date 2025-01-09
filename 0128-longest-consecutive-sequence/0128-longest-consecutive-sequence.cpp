class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        if(nums.size()==0) return 0;
        int ans=1;
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]) c++;
            else c=1;
            ans=max(ans,c);
        }
        return ans;
    }
};