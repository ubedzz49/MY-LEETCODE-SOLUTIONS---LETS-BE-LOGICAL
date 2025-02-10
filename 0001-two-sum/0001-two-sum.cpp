class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> n(2);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                
                    if(nums[i]+nums[j]==target){
                       n[0]=i;
                       n[1]=j;
                        return n;
                    }
            }
        }
        return {};
    }
};