class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        for(auto it:intervals){
            pq.push({it[1],it[0]});
        }
        int le=INT_MIN;
        int c=0;
        while(!pq.empty()){
            if(pq.top()[1]<le) c++;
            else le=pq.top()[0];
            pq.pop();
        }
        return c;
    }
};