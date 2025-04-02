class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int prev=INT_MIN;
        int c=0;
        int ans=0;
        for(auto it:nums){
            if(it>prev){
                c++;
            }
            else{
                ans=max(ans,c);
                c=1;
            }
            prev=it;
        }
        return max(ans,c);
    }
};