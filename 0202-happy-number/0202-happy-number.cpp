class Solution {
public:
int sqsm(int n){
    int sum=0;
    while(n>0){
        sum+=((n%10)*(n%10));
        n=n/10;
    }
    return sum;
}
    bool isHappy(int n) {
        set<int> sett;
        //sett.insert(n);
        while(n!=1){
            if(sett.count(sqsm(n))!=0){
                cout<<n;
                return false;
            }
            n=sqsm(n);
            sett.insert(n);
        }
        return true;
    }
};