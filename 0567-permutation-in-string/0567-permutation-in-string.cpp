class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     if(s1.size()>s2.size()){
        return false;
     }
     vector<int> s1c(26,0);
     vector<int> s2c(26,0);
     for(int i=0;i<s1.size();i++){
        int n=s1[i]-'a';
        s1c[n]++;
        n=s2[i]-'a';
        s2c[n]++;
     }
     if(s1c==s2c){
        return true;
     }
     for(int i=s1.size();i<s2.size();i++){
        int n=s2[i]-'a';
        s2c[n]++;
        n=s2[i-s1.size()]-'a';
        s2c[n]--;
        if(s1c==s2c){
            return true;
        }
     }
     return false;
    }
};