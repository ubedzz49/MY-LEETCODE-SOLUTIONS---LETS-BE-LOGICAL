class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> fl1={};
        vector<vector<vector<int>>> fl(101,fl1);

        for(auto i:flights){
            fl[i[0]].push_back({i[1],i[2]});
        }

        for(int i=0;i<fl.size();i++){
            for(auto j:fl[i]){
            }
            cout<<endl;
        }

        vector<int> cf(101,INT_MAX);
        queue<vector<int>> q;
        cf[src]=0;
        q.push({0,src,0});
        while(!q.empty()){
            vector<int> v=q.front();
            int cost=v[0];
            int ap=v[1];
            int stop=v[2];
            q.pop();
            for(auto i:fl[ap]){
                if(stop<=k && cost+i[1]<cf[i[0]]){
                    cf[i[0]]=cost+i[1];
                    q.push({cost+i[1],i[0],stop+1});
                }
            }
        }
        if(cf[dst]==INT_MAX){
            return -1;
        }
        return cf[dst];
    }
};