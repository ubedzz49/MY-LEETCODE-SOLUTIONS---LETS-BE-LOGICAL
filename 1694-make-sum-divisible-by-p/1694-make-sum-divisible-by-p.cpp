class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    
        int minLen = nums.size(), n = nums.size(), SUM = 0;
        int target = accumulate(nums.begin(), nums.end(), 0, [&](int acc, int i) {return (acc + i) % p;});
        if (target == 0) return 0;
        unordered_map<int, int> mapMOD = { {0, -1} };
        
        for (int j = 0; j < n; j++) {
            SUM = (SUM + nums[j]) % p;
            int RMD = (SUM - target + p) % p;
            if (mapMOD.find(RMD) != mapMOD.end()) {
                int i = mapMOD[RMD];
                minLen = min(minLen, j - i);
            }
            mapMOD[SUM] = j;
        }

        if (minLen == n) return -1;
        return minLen;
    }
};