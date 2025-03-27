class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mpp;
        int res = 0;
        int i = 0, j = 0, n = s.size();
        while(j < n){
            mpp[s[j]]++;
            while(mpp.size() == 3){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                res += n - j;
                i++;
            }
            j++;
        }
        return res;
    }
};