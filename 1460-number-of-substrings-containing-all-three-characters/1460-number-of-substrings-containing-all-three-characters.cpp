class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> c(3,0);
        int ans=0;
        int st=0;
        for(int i=0;i<s.size();i++){
            c[s[i]-'a']++;
            if(c[1]>=1 && c[0]>=1 && c[2]>=1){
                //ans+=(s.size()-i);
            for(int j=st;j<i;j++){
                if(c[s[j]-'a']>0) {ans+=(s.size()-i);st++; c[s[j]-'a']--;
                if(c[s[j]-'a']==0) break;
                }
                else break;
            }
            }
        }
        return ans;
    }
};