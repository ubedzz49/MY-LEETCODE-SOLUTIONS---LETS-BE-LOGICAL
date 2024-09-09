class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]++;
        }
        map<int,int> mp;
        vector<int> a1,a2;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
            if(mpp[nums1[i]]==0){
                a1.push_back(nums1[i]);
            }
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]==0){
                a2.push_back(nums2[i]);
            }
            mp[nums2[i]]++;
        }
        return {a1,a2};
    }
};