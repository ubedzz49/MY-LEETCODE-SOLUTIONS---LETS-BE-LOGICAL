class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        
        int mx = 0;  // To store the maximum width ramp
        
        // Traverse from the end of the array to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Try to find the largest width ramp possible
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                mx = max(mx, i - st.top());
                st.pop();  // Remove the index since we have found the ramp
            }
        }
        
        return mx;
    }
};
