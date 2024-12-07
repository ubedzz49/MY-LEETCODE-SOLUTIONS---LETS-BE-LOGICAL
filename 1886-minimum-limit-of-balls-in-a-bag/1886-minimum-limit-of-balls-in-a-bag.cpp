class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right = *max_element(nums.begin(), nums.end());
        int left = 1;
        while (left < right) {        
            int mid = left + (right - left) / 2;
            if (req_op(mid, nums) <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int req_op(int val, vector<int>& v) {
        int res = 0, sz = v.size();
        for (int i = 0; i < sz; i++) {
            if (v[i] % val == 0) {
                res += (v[i] / val - 1);
            } else {
                res += v[i] / val;
            }
        }
        return res;
    }
};