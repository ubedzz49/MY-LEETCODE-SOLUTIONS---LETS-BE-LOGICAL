class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int c=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                c++;
                if(c>2) continue;
                ans+=s[i];
            }
            else{
                c=1;
                ans+=s[i];
            }
        }
        return ans;
    }
};