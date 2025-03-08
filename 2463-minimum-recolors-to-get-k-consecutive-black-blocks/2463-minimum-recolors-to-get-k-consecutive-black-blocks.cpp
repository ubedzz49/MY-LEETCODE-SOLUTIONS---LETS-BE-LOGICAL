class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cntb=0;
        int i=0;
        int n=blocks.size();
        int j=0;
        while(j<n && j<k){
            if(blocks[j]=='B')cntb++;
            j++;
        }
        j--;
        int maxcnt=cntb;
        while(j<n){
             if(blocks[i]=='W' && blocks[j+1]=='B'){
                cntb++;
             }
             else if(blocks[i]=='B' && blocks[j+1]=='W'){
                cntb--;
             }
             maxcnt=max(cntb,maxcnt);
             i++;
             j++;
        }
        return k-maxcnt;

    }
};