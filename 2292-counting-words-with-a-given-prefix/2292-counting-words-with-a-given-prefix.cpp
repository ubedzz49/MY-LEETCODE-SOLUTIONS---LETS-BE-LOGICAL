class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(auto it:words){
            string s=it.substr(0,pref.size());
            if(s==pref) c++;
        }
        return c;
    }
};