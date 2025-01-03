class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> pre;
        long long c=0;
        for(auto it:nums){
            c+=it;
            pre.push_back(c);
        }
        long long sum=c;
        c=0;
        for(int i=0;i<pre.size()-1;i++){
            if(pre[i]>=sum-pre[i])c++;
        }
        return c;
    }
};