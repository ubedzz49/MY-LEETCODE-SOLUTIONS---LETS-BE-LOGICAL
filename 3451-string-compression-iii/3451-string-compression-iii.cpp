class Solution {
public:
    string compressedString(string s) {
        //s.push_back('1');
        string ans="";
        int c=0;
        for(int i=0;i<s.size();i++){
            if(i!=s.size()-1 && s[i]==s[i+1]){
                c++;
            }else{
                c++;
                ans.push_back((c+'0'));
                ans.push_back(s[i]);
                c=0;
            }
            if(c==9){
                ans.push_back((c+'0'));
                ans.push_back(s[i]);
                c=0;
            }
        }
        return ans;
    }
};