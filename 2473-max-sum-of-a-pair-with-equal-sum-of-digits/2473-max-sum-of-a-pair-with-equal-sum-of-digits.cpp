class Solution {
public:
int digsum(int n){
    int ans=0;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mpp;
        int ans=-1;
        for(auto it:nums){
            int d=digsum(it);
            if(mpp[d].second<it){
                mpp[d]=make_pair(mpp[d].second+it,it);
            }
            else if(mpp[d].second+it>mpp[d].first)mpp[d].first=mpp[d].second+it;
            if(mpp[d].first!=mpp[d].second) ans=max(ans,mpp[d].first);
        }
        return ans;
    }
};