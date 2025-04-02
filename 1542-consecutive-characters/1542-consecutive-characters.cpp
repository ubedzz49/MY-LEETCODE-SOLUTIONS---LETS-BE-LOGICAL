class Solution {
public:
    int maxPower(string s) {
       int c=0;
       int ans=0;
       char prev='1';
       for(auto it:s){
        if(it==prev){
            c++;
        }
        else{
            ans=max(ans,c);
            c=1;
        }
        prev=it;
       } 
       ans=max(ans,c);
       return ans;
    }
};