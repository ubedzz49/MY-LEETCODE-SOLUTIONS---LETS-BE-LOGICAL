#define MOD 1000000007
#define ll long long

class Solution {
public:
    ll mod_power(ll a, ll p, ll mod = MOD) {
        ll ans = 1LL;
        while (p > 0) {
            if (p & 1)
                ans = (ans % mod * (a % mod)) % mod;
            a = (a % mod * (a % mod)) % mod;
            p >>= 1;
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScore;

        auto findScore = [&](int ele) -> int {
            int cnt = 0;
            for (int i = 2; i * i <= ele; i++) {
                if (ele % i == 0) {
                    while (ele % i == 0)
                        ele /= i;
                    cnt++;
                }
                if (ele == 1)
                    break;
            }

            cnt += ele != 1;
            return cnt;
        };

        for (auto it : nums) {
            primeScore.push_back(findScore(it));
        }

        vector<pair<int, int>> sortNums;
        for (int i = 0; i < n; i++)
            sortNums.push_back({nums[i], i});

        sort(sortNums.rbegin(), sortNums.rend());

        ll ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            ll idx = sortNums[i].second;
            ll ps = primeScore[idx];

            ll left = idx - 1, right = idx + 1;

            while (0 <= left && primeScore[left] < ps)
                left--;
            while (right < n && primeScore[right] <= ps)
                right++;

            left++;
            right--;

            ll numLen = (idx - left + 1) * (right - idx + 1);

            int len = min(numLen, (ll)k);

            ans = (ans % MOD * mod_power(sortNums[i].first, len, MOD)) % MOD;
            k -= len;
        }

        return ans;
    }
};