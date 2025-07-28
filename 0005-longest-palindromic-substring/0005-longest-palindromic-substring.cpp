class Solution {
public:
    string longestPalindrome(string s) {
         
         int l=1;
         int r=1;
         int ans=1;
         for(int i=0;i<s.size();i++){
            int ll=i;
            int rr=i;
            int len=1;
            while(ll>0 && rr+1<s.size()){
                ll--;
                rr++;
                if(s[ll]==s[rr]) {
                    len+=2;
                if(len>ans) {
                ans=len;
                r=rr;
                l=ll;
            }
            }
                else break;
            }
            
         }

         for(int i=1;i<s.size();i++){
            int ll=i-1;
            int rr=i;
            int len=2;
            if(s[ll]==s[rr]){
                if(len>ans) {
                ans=len;
                r=rr;
                l=ll;
            }
            }
            else continue;
            while(ll>0 && rr+1<s.size()){
                ll--;
                rr++;
                if(s[ll]==s[rr]) {
                    len+=2;
                if(len>ans) {
                ans=len;
                r=rr;
                l=ll;
            }
            }
                else break;
            }
            
         }

         string anss="";
         for(int i=l;i<=r;i++) anss+=s[i];
         return anss;
    }
};