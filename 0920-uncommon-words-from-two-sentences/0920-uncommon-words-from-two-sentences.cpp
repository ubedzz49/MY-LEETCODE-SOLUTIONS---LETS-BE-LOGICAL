class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mpp;
        string a="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                    mpp[a]++;
                    cout<<a<<" ";
                    a="";
            }else{
                a+=s1[i];
            }
        }
            mpp[a]++;
            a="";
        vector<string> ans;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                mpp[a]++;
                a="";
            }else{
                a+=s2[i];
            }
        }
        mpp[a]++;
                
                for(auto i:mpp){
                    if(i.second!=1){
                        continue;
                    }
                    ans.push_back(i.first);
                }
        return ans;
    }
};