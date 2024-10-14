class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0]+1;
        }
        int sqsm=nums[0];
        int fss=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sqsm+=nums[i];
            }else{
                fss=max(sqsm,fss);
                break;
            }
        }
        fss=max(sqsm,fss);
        set<int> sett;
        for(auto i:nums){
            sett.insert(i);
        }
        for(int i=fss;;i++){
            if(sett.count(i)==0){
                return i;
            }
        }
        return 0;
    }
};