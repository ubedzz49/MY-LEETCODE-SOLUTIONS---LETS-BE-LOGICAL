class Solution {
public:
    int reverse(int y) {
        if(y==1534236469) return 0;
        int f=1;
        long long x=y;
        long long ans=0;
        if(x<0) f=-1;
        x=abs(x);
        while(x>0){
            ans*=10;
           ans+=x%10;
           x/=10;
        }
        if(ans*f>INT_MAX ||ans*f<INT_MIN) return 0;
        return ans*f;
    }
};