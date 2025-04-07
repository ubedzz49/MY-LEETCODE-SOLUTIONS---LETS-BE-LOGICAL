class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="";
        int c=0;
        for(int i=0;i<max(a.size(),b.size());i++){
            int aa=0;
            if(i<a.size() && a[i]=='1') aa=1;
            int bb=0;
            if(i<b.size() && b[i]=='1') bb=1;
            int r=aa+bb+c;
            if(r==3){
                ans+='1';
                c=1;
            }
            else if(r==2){
                ans+='0';
                c=1;
            }
            else if(r==1){
                ans+='1';
                c=0;
            }
            else{
                ans+='0';
                c=0;
            }
        }
        int r=c;
            if(r==3){
                ans+='1';
                c=1;
            }
            else if(r==2){
                ans+='0';
                c=1;
            }
            else if(r==1){
                ans+='1';
                c=0;
            }
            else{
                ans+='0';
                c=0;
            }
            reverse(ans.begin(),ans.end());
            a="";
            bool bb=false;
            for(int i=0;i<ans.size();i++){
                if(ans[i]=='1') bb=true;
                if(bb) a+=ans[i];
            }
            if(a=="") return "0";
        return a;
    }
};