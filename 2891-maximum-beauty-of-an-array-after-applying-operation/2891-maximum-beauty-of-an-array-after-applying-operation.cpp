class Solution {
public:
    int diff[300002];
    int maximumBeauty(vector<int>& nums, int k) {
        int l=1e9, r=0;
        for(int num:nums){
            diff[num-k+100000]++;
            diff[num+k+100001]--;
            l = min(l,num-k+100000);
            r = max(r,num-k+100001);
        }
        int val=0, mx=-1;
        for(int i=l-1;i<r+2;i++){
            val+=diff[i];
            mx = max(val,mx);
        }
        return mx;
    }
};