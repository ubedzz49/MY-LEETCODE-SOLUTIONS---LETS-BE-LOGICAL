class Solution {
public:
    bool canJump(vector<int>& nums) {
        // vector<bool> isvis(nums.size(),0);
        // isvis[0]=1;
        // for(int i=0;i<nums.size();i++){
        //     if(isvis[i]==0) continue;
        //     for(int j=1;j<=nums[i];j++){
        //         if(i+j<isvis.size()) isvis[i+j]=1;
        //         else break;
        //     }
        // }
        // return isvis[isvis.size()-1];
        int last=0;
        for(int i=0;i<nums.size();i++){
            if(i>last) return false;
            last=max(last,i+nums[i]);
        }
        return true;
    }
};