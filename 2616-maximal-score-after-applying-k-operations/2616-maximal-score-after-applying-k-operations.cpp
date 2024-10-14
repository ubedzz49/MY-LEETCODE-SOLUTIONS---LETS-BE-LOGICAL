class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        long long score=0;
        while(k>0){
            k--;
            int n=pq.top();
            pq.pop();
            score+=n;
            if(n%3==0){
            n=floor(n/3);
            }else{
                n=floor(n/3)+1;
            }
            pq.push(n);
        }
        return score;
    }
};