class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        if (m * n == 1) return 0; 
        
        vector<int> arr;
        arr.reserve(m * n); 
        int rem = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != rem) return -1;
                arr.push_back(grid[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        int op = 0;
        for (int num : arr) {
            op += abs(num - median) / x;
        }
        return op;
    }
};