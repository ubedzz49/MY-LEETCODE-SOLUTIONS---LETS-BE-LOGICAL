class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long mx=0;
        long long mn=0;
        long long sum=0;
        for(auto it:diff) {
            sum+=it;
            mx=max(mx,sum);
            mn=min(mn,sum);
        }
        int a=mx-mn;
        return max((upper-lower+1)-a,0);
    }
};