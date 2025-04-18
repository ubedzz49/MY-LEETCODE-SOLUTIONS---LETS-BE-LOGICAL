class Solution {
    public:
    string encode(const string& s) {
        const int n = s.size();
        char prev = s[0];
        int count = 1;
        stringstream ss;
        for (int i = 1; i < n; ++i) {
            if (prev == s[i]) ++count;
            else {
                ss << count << prev;
                prev = s[i];
                count = 1;
            }
        }
        ss << count << prev;
        return ss.str();
    };


    string countAndSay(const int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) s = encode(s);
        return s;
    }
};