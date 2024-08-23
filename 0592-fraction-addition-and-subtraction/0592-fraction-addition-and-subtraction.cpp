class Solution {
public:

string its(long long n){
    if(n==0){
        return "0";
    }
    string s="";
    bool b=1;
    if(n<0){
        n=-n;
        b=0;
    }
    while(n>0){
        int m='0'+n%10;
        char c=m;
        s+=c;
        n=n/10;
    }
    reverse(s.begin(),s.end());
    if(b==0){
        s="-"+s;
    }
    return s;
}

void ins(vector<int>& num,vector<int>& den,string s,bool b){
    string n="";
    string d="";
    int a=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='/'){
            a=1;
            continue;
        }
        if(a==0){
            n+=s[i];
        }else{
            d+=s[i];
        }
    }
    int nu=0;
    int de=0;
    for(int i=n.size()-1;i>=0;i--){
        int c=n[i]-'0';
        nu+=(c*pow(10,n.size()-1-i));
    }
    for(int i=d.size()-1;i>=0;i--){
        int c=d[i]-'0';
        de+=(c*pow(10,d.size()-1-i));
    }
    if(b==0){
        nu=-nu;
    }
    num.push_back(nu);
    den.push_back(de);
}
    string fractionAddition(string exp) {
        vector<int> num;
        vector<int> den;
        string st="";
        int j=0;
        bool b=1;
        if(exp[0]=='-'){
            b=0;
            j++;
        }
        if(exp[0]=='+'){
            j++;
        }
        for(int i=j;i<exp.size();i++){
            if(exp[i]=='-'){
                ins(num,den,st,b);
                st="";
                b=0;
                continue;
            }
            if(exp[i]=='+'){
                ins(num,den,st,b);
                st="";
                b=1;
                continue;
            }
            if(i==exp.size()-1){
                st+=exp[i];
                ins(num,den,st,b);
            }
            st+=exp[i];
        }
        long long deno=1;
        vector<int> usg=den;
        usg.erase(unique(usg.begin(),usg.end()),usg.end());
        for(int i=0;i<usg.size();i++){
            deno=deno*usg[i];
        }
        long long nume=0;
        for(int i=0;i<num.size();i++){
            nume+=(num[i]*(deno/den[i]));
        }
        for(int i=max(nume,deno)/2+1;i>0;i--){
            if(nume%i==0 && deno%i==0){
                nume=nume/i;
                deno=deno/i;
                break;
            }
        }
        if(nume==0){
            return "0/1";
        }
        if(nume%deno==0){
            return its(nume/deno)+"/1";
        }
        return its(nume)+"/"+its(deno);
    }
};