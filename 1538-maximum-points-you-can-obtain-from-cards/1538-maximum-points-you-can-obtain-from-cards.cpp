class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        if(k==nums.size()) return accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int ans=sum;
        int ssum=sum;
        sum=0;
        int kk=k-1;
        for(int i=nums.size()-1;i>=nums.size()-k;i--){
            sum+=nums[i];
            ssum-=nums[kk];
            kk--;
            int currsum=sum+ssum;
            ans=max(ans,currsum);
        }
        return ans;
    }
};