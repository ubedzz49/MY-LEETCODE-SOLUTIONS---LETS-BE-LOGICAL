class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int c=0;
        for(int i=0;i<gas.size()*2;i++){
                st=st-cost[i%gas.size()]+gas[i%gas.size()];
                c++;
                if(st<0){
                    c=0;
                    st=0;
                }
                if(c==gas.size()){
                    return i-gas.size()+1;
                }
            }
        return -1;
    }
};