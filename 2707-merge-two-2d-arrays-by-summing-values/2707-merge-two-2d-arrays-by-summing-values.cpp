class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int sum=0;
        map<int,int>m;
        for(auto i: nums1) m[i[0]]+=i[1];
        for(auto i: nums2) m[i[0]]+=i[1];

        for(auto i:m) ans.push_back({i.first,i.second});
        return ans;
    }
};