class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums1) {
        if(nums1.size()==0){
            return nums1;
        }
        vector<int> nums=nums1;
        sort(nums.begin(),nums.end());
        map<int,int> mpp;
        int c=1; 
        mpp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                c++;
            }
            mpp[nums[i]]=c;
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mpp[nums1[i]];
        }
        return nums1;
    }
};