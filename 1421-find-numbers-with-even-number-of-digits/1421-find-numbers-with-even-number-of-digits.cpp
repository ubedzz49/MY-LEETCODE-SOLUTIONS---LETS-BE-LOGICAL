class Solution {
public:
int dig(int n){
    int c=0;
    while(n>0){
        n/=10;
        c++;
    }
    return c;
}
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it:nums) if(!(dig(it)&1)) ans++;
        return ans;
    }
};