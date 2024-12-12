class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(auto it:gifts) pq.push(it);
        while(k>0){
            k--;
            int n=pq.top();
            pq.pop();
            n=sqrt(n);
            pq.push(n);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};