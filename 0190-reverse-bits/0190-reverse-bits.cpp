class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int c=31;
        uint32_t ans=0;
        while(n>0){
            cout<<c<<" ";
            ans+=(n&1)*(1<<c);
            c--;
            n=n>>1;
        }
        return ans;
    }
};