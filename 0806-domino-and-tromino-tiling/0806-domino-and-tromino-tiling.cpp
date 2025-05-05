class Solution {
public:
int mod=1e9+7;
    int numTilings(int n) {
        long long a,b,c;
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        if(n==4) return 11;
        if(n==5) return 24;
        a=5,b=11,c=24;
        for(int i=6;i<=n;i++){
            int newc=(c*2LL%mod+a%mod)%mod;
            a=b;
            b=c;
            c=newc;
        }
        return c;
    }
};