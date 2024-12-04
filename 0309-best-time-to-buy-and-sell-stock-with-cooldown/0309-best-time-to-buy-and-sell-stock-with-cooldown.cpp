class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=-prices[0];
        int c=0;
        int s=0;
        for(int i=1;i<prices.size();i++){
            int tb=b,tc=c,ts=s;
            b=max(tb,tc-prices[i]);
            c=max(tc,ts);
            s=max(ts,tb+prices[i]);
        }
        return max(b,max(s,c));
    }
};