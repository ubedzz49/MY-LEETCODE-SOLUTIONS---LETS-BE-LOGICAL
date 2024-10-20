class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  
                if (any_of(freq.begin(), freq.end(), [&](int f){ return f >= k; })) {
                    ans++;
                }
            }
        }
        return ans;
    }
};