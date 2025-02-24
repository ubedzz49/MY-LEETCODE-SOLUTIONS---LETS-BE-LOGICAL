class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target){ ans=m; j=m-1;}
            else {ans=m+1; i=m+1;}
        }
        return ans;
    }
};