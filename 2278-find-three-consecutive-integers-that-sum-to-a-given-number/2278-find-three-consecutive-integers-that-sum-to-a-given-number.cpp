class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};
        long long l=num/3;
        vector<long long> ans={l-1,l,l+1};
        return ans;
    }
};