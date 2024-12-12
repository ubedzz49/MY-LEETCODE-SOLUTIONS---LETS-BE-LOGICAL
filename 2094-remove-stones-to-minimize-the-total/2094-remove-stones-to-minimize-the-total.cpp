class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
         priority_queue<int> pq;
        for(auto it:piles) pq.push(it);
        while(k>0){
            k--;
            int n=pq.top();
            pq.pop();
            n=n-n/2;
            pq.push(n);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};