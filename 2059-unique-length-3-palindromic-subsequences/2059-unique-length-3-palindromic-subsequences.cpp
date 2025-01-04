class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        int result = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int left = first[c - 'a'], right = last[c - 'a'];
            if (left != -1 && left + 1 < right) {
                unordered_set<char> uniqueChars;
                for (int i = left + 1; i < right; i++) {
                    uniqueChars.insert(s[i]);
                }
                result += uniqueChars.size();
            }
        }

        return result;
    }
};
