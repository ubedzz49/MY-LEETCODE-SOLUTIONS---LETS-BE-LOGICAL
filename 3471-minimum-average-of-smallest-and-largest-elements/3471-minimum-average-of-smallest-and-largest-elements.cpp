class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans=INT_MAX;
        while(nums.size()>1){
            double d=(nums[0]+nums[nums.size()-1]);
            d/=2;
            if(d<ans) ans=d;
            nums.erase(nums.begin());
            nums.pop_back();
        }
        if(nums[0]<ans) ans=nums[0];
        return ans;
    }
};