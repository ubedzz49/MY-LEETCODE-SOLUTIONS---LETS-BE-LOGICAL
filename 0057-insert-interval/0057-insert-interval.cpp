class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newint) {
        ints.push_back(newint);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(auto it:ints) pq.push(it);
        int st=pq.top()[0];
        int end=pq.top()[1];
        pq.pop();
        vector<vector<int>> ans;
        while(!pq.empty()){
            int s=pq.top()[0];
            int e=pq.top()[1];
            pq.pop();
            if(s<=end) end=max(e,end);
            else{
                ans.push_back({st,end});
                st=s;
                end=e;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};