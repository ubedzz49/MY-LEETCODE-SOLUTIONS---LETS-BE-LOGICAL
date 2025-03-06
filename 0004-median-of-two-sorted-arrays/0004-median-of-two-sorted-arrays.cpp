class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int t=0;
        int s=nums1.size()+nums2.size();
        int f=s/2;
        if((s&1)==0) f--;
        while(t<f){
            if(i==nums1.size()){j++;t++; continue;}
            if(j==nums2.size()){i++;t++; continue;}
            if(nums1[i]<nums2[j]) i++;
            else j++;
            t++;
        }
        if((s&1)==1){ 
            if(i==nums1.size()) return nums2[j];
            if(j==nums2.size()) return nums1[i];
            return min(nums1[i],nums2[j]);}
        vector<int> v;
        if(i<nums1.size()) v.push_back(nums1[i]);
        if(i+1<nums1.size()) v.push_back(nums1[i+1]);
        if(j<nums2.size()) v.push_back(nums2[j]);
        if(j+1<nums2.size()) v.push_back(nums2[j+1]);
        sort(v.begin(),v.end());
        int fr=(float) v[0];
        int sc=(float) v[1];
        float sm=fr+sc;
        return (float)sm/2.0;
    }
};