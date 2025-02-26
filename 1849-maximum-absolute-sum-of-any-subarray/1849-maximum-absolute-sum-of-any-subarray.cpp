class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mxs=0;
        int mns=0;
        int ans=0;
        for(auto it:nums){
            if(mxs+it>0){ mxs+=it; ans=max(mxs,ans);}
            else mxs=0;
            if(mns+it<0){ mns+=it; ans=max(ans,abs(mns));}
            else mns=0;
        }
        return ans;
    }
};