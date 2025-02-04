class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fv=0,tn=0;
        for(auto it:bills){
            if(it==5) fv++;
            if(it==10) tn++;
            int am=it-5;
            while(am!=0){
                if(10<=am && tn>0){
                    am-=10;
                    tn--;
                }else{
                    if(fv==0) return false;
                    am-=5;
                    fv--;
                }
            }
        }
        return true;
    }
};