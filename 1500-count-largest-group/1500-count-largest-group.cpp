class Solution {
public:
int digsum(int n){
    int ans=0;
    while(n>0){
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        for(int i=1;i<=n;i++){
            mpp[digsum(i)]++;
        }
        int mx=-1;
        for(auto it:mpp){
            mx=max(mx,it.second);
        }
        int ans=0;
        for(auto it:mpp) if(it.second==mx) ans++;
        return ans;
    }
};