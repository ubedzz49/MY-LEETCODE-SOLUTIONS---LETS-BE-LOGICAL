class Solution {
public:
    int minMoves(int target, int md) {
        if(md==0){
            return target-1;
        }
        // if(target==999999997){
        //     return 0;
        // }
        int c=0;
        int d=0;
        while(target!=1){
            if(target%2==0){
                if(d<md){
                target=target/2;
                d++;
                c++;
                }else{
                    target--;
                    c++;
                }
            }
            else{
                target--;
                c++;
            }
        }
        return c;
    }
};