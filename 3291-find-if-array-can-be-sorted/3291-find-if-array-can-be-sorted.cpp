class Solution {
public:
int countones(int a){
    int c=0;
    while(a>0){
        if(a%2==1) c++;
        a=a/2;
    }
    return c;
}
    bool canSortArray(vector<int>& nums) {
        vector<int> nums2=nums;
        sort(nums2.begin(),nums2.end());
        int po=countones(nums[0]);
        map<int,bool> mpp1;
        mpp1[nums[0]]=1;
        map<int,bool> mpp2;
        mpp2[nums2[0]]=1;
       for(int i=1;i<nums.size();i++){
        int co=countones(nums[i]);
        if(co!=po){
            if(mpp1!=mpp2) return false;
        }
        po=co;
        mpp1[nums[i]]=1;
        mpp2[nums2[i]]=1;
       }
       return true;
    }
};