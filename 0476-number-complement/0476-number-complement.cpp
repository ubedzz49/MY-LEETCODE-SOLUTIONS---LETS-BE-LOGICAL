class Solution {
public:
    int findComplement(int num) {
        int c=0;
        int ans=0;
        while(num>=1){
            if(num%2==0){
                ans+=(pow(2,c));
            }
            c++;
            num=num/2;
        }
        return ans;
    }
};