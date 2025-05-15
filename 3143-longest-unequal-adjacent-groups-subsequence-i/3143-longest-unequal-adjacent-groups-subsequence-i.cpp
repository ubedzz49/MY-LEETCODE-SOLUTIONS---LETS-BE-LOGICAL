class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result1, result2;
        int n = words.size();
        int expected = 0;
        for (int i = 0; i < n; i++) {
            if (groups[i] == expected) {
                result1.push_back(words[i]);
                expected ^= 1;
            }
        }
        expected = 1;
        for (int i = 0; i < n; i++) {
            if (groups[i] == expected) {
                result2.push_back(words[i]);
                expected ^= 1;
            }
        }
        return result1.size() >= result2.size() ? result1 : result2;
    }
};