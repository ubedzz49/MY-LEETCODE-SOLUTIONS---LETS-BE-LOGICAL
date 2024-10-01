class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        map<int,int> mpp;
        int c=0;
       for(int i=0;i<nums.size();i++){
        int n=nums[i]%k;
        if(n==0){
            c++;
            continue;
        }
        if(n<0){
            n=k+n;
        }
        mpp[n]++;
       }
       if(c%2!=0){
        return false;
       }
       for(auto i:mpp){
        if(i.second!=mpp[k-i.first]){
            return false;
        }
       }
       return true;
    }
};