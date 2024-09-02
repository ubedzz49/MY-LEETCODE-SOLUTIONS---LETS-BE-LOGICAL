class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        long long sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            }
            k%=sum;
        
        for(int i=0;i<nums.size();i++){
            k-=nums[i];
            if(k<0){
                return i;
            }
        }
        return -1;
    }
};