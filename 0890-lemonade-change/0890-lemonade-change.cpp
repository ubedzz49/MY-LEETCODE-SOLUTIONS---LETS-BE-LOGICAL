class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0;
        int tn=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                f++;
                continue;
            }
            if(bills[i]==10){
                if(f>0){
                    f--;
                    tn++;
                    continue;
                }else{
                    return 0;   
                }
            }
            if(bills[i]==20){
                if(tn>=1 && f>=1){
                    tn--;
                    f--;
                    continue;
                }
                else if(f>=3){
                    f-=3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};