class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++) pq.push(make_pair(nums[i],i));
        map<int,bool> mpp;
        vector<int> ans;
        while(k>0){
            k--;
            mpp[pq.top().second]=1 ;
            pq.pop();
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};