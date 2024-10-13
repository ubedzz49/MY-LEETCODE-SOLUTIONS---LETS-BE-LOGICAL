#include <queue>
class Solution {
public:
    struct compare{
        bool operator()(const vector<int>& a,const vector<int>& b){
            return a[0] > b[0];
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        int max = INT_MIN;;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], i, 0});
            max = max > nums[i][0] ? max : nums[i][0];  
        }        
        int rs = 0, re = INT_MAX;
        while(true){
            vector<int> top = pq.top();
            pq.pop();
            if(max - top[0] < re - rs){
                re = max;
                rs = top[0];
            }

            if(top[2] == nums[top[1]].size() - 1) break;
            int next = nums[top[1]][top[2] + 1];
            pq.push({next, top[1], top[2] + 1});
            max = max > next ? max : next;
        }
        return {rs, re};
    }
};