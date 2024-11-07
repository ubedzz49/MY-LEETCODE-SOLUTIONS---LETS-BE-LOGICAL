class Solution {
    void countones(int n,unordered_map<int,int>& mpp){
        int c=0;
        while(n>0){
           if(n%2==1) mpp[c]++;
           n/=2;
           c++;
        }
    }
public:
    int largestCombination(vector<int>& can) {
        unordered_map<int,int> mpp;
        for(auto it:can) countones(it,mpp);
        int ans=0;
        for(auto it:mpp) ans=max(ans,it.second);
        return ans;
    }
};