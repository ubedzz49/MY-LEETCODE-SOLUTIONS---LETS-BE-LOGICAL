class Solution {
public:
    bool checkTwoChessboards(string c, string d) {
        int n1=c[0]-'a';
        int m1=d[0]-'a';
        int n2=c[1]-'0';
        int m2=d[1]-'0';
        bool b1=0;
        bool b2=0;
        if((n1%2==0 && n2%2==0) || (n1%2!=0  && n2%2!=0)){
            b1=1;
        }
         if((m1%2==0 && m2%2==0) || (m1%2!=0  && m2%2!=0)){
            b2=1;
        }
        if(b1==b2){
            return 1;
        }
        return 0;
    }
};