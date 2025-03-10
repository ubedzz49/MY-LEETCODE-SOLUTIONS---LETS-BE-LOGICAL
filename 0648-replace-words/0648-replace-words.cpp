class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,bool> mpp;
        for(auto it:d) mpp[it]=1;
        d={};
        string c="";
        for(auto it: s){
            if(it==' '){
                d.push_back(c);
                //cout<<c<<" ";
                c="";
            }
            else c+=it;
        }
        //cout<<c<<endl;
        d.push_back(c);
        string ans="";
        for(auto it:d){
            cout<<endl;
            c="";
            bool b=false;
            for(auto ch:it){
                c+=ch;
                //cout<<c<<" ";
                if(mpp[c]){
                    //cout<<mpp[c]<<"--";
                    ans+=c;
                    ans+=' ';
                    //it=c;
                    b=true;
                    break;
                }
            }
            if(b==true) continue;
            ans+=c;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};