class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(auto it:s) mpp[it]++;
        bool b=false;
        int l=0;
        for(auto it:mpp){
            if(it.second%2==1) b=true;
            l+=(it.second-it.second%2);
        }
        if(b) return l+1;
        return l;
    }
};