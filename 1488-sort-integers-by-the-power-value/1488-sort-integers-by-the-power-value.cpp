class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=lo;i<=hi;i++){
            int x=i;
            int p=1;
            while(x!=1){
                p++;
                if(x%2==0) x/=2;
                else x=3*x+1;
            }
            pq.push({p,i});
        }
        while(k>1){
            k--;
            pq.pop();
        }
        return pq.top()[1];
    }
};