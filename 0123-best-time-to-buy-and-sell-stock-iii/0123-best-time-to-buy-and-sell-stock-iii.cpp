class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb=-prices[0];
        int fdb=0;
        int sb=INT_MIN;
        int sdb=0;
        for(int i=1;i<prices.size();i++){
            int tfb=max(fb,-prices[i]);
            int tfdb=max(fb+prices[i],fdb);
            int tsb=max(sb,fdb-prices[i]);
            int tsdb=max(sb+prices[i],sdb);
            fb=tfb;
            fdb=tfdb;
            sb=tsb;
            sdb=tsdb;
        }
        
        return max(max(fb,fdb),max(sb,sdb));
    }
};