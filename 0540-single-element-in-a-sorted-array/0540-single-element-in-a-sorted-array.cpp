class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            c++;
            if(c%2==1 && nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};