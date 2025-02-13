class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto it:nums) pq.push(it);
        bool b=false;
        int ans=0;
        while(pq.size()>=2){
            long long n=pq.top();
            pq.pop();
            long long m=pq.top();
            pq.pop();
            cout<<m<<" "<<n<<endl;
            if(n>=k) return ans;
            pq.push(n+n+m);
            ans++;
        }
        return ans;
    }
};