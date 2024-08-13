class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> mpp;
        string a="";
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                mpp[a.size()].push_back(a);
                a="";
            }else{
                a+=text[i];
            }
        }
        mpp[a.size()].push_back(a);
       a="";
       for(auto i:mpp){
        for(int j=0;j<i.second.size();j++){
            a+=i.second[j]+" ";
        }
       }
       string ans="";
       for(int i=0;i<a.size()-1;i++){
        if(a[i]==' '){
            ans+=a[i];
            continue;
        }
        int n=a[i];
        if(i==0 && n>96){
            char c=n-32;
            ans+=c;
            continue;
        }
        if(i!=0 && n<96){
            char c=n+32;
            ans+=c;
            continue;
        }
        ans+=a[i];
        
       }
       return ans;
    }
};