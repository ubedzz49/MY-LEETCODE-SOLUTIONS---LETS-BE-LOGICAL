class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string w="";
        string ans="";
        int c=0;
        for(int i=0;i<s.size();i++){
            if(c<spaces.size() && i==spaces[c]){
                ans+=w;
                ans+=" ";
                c++;
                w="";
            }
            w+=s[i];
        }
        ans+=w;
        return ans;
    }
};