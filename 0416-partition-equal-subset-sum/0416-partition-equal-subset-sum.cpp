class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2==1) return false;
        s=s/2;
        vector<bool> pos(s+1,0);
        if(nums[0]>s) return false;
        pos[nums[0]]=true;
        pos[0]=true;
        for(int i=1;i<nums.size();i++){
            vector<bool> next(s+1,0);
            if(nums[i]>s) return false;
            for(int j=0;j<=s;j++){
                if(pos[j]==true){
                    next[j]=true;
                    if(j+nums[i]<=s) next[j+nums[i]]=true;
                }
            }
            pos=next;
        }
        return pos[s];
    }
};