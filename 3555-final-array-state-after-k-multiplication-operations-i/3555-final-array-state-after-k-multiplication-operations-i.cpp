class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});
        while(k>0){
            k--;
            vector<int> v=pq.top();
            pq.pop();
            v[0]=v[0]*multiplier;
            pq.push(v);
        }
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            nums[v[1]]=v[0];
        }
        return nums;
    }
};