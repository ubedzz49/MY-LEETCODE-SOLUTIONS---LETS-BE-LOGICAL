class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b=-prices[0];
        int nb=0;
        for(int i=1;i<prices.size();i++){
            int tb=b;
            b=max(nb-prices[i],tb);
            nb=max(tb+prices[i]-fee,nb);
        }
        return max(b,nb);
    }
};