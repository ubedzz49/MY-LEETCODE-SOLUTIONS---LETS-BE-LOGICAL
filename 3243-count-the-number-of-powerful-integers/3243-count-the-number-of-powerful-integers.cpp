class Solution {
public:
    long long solve(string& s, string& suffix, int limit) {
        int n = s.size(), m = suffix.size(), rem = n - m;
        if (n < m) return 0;
        long long ans = 0;
        string sSuffix = s.substr(rem);
        for (int i = 0; i < rem; i++) {
            int val = s[i] - '0';
            if (val <= limit) {
                ans += val * pow(limit + 1, rem - i - 1);
            } else {
                ans += pow(limit + 1, rem - i);
                return ans;
            }
        }
        if (sSuffix >= suffix) ans++;
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string low = to_string(start - 1), high = to_string(finish);
        return solve(high, s, limit) - solve(low, s, limit);
    }
};
