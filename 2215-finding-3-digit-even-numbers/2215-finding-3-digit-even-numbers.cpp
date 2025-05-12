class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0), freq2(10,0);
        for (auto x : digits) {
            freq[x]++;
        }

        vector<int> cnt;
        for (int i = 100; i <= 999; i++) {
            fill(freq2.begin(), freq2.end(), 0);
            int x = i;
            while (x) {
                freq2[x % 10]++;
                x /= 10;
            }
            int j;
            for (j = 0; j < 10; j++) {
                if (freq2[j] > freq[j]) break;
            }
            if (j == 10 && (i % 2 == 0)) {
                cnt.push_back(i);
            }
        }
        return cnt;
    }
};