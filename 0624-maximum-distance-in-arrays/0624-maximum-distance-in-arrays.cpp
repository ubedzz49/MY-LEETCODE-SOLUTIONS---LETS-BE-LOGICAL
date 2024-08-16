class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int mni=0;
        int mxi=0;
        int mn=nums[0][0];
        int mx=nums[0][nums[0].size()-1];
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]<mn){
                mn=nums[i][0];
                mni=i;
            }
            if(nums[i][nums[i].size()-1]>mx){
                mx=nums[i][nums[i].size()-1];
                mxi=i;
            }
        }
        if(mxi!=mni){
            return abs(mx-mn);
        }
        int sum1=-1;
        for(int i=0;i<nums.size();i++){
            if(i==mxi){
                continue;
            }
            sum1=max(sum1,abs(mx-nums[i][0]));
        }
        int sum2=-1;
        for(int i=0;i<nums.size();i++){
            if(mni==i){
                continue;
            }
            sum2=max(sum2,abs(mn-nums[i][nums[i].size()-1]));
        }
        return max(sum1,sum2);

    }
};