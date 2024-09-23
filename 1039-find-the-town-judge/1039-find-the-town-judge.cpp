class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        vector<pair<set<int>,set<int>>> adjl(n+1);
        for(int i=0;i<trust.size();i++){
            adjl[trust[i][1]].first.insert(trust[i][0]);
            adjl[trust[i][0]].second.insert(trust[i][1]);
        }
        int c=0;
        for(auto i:adjl){
            if(i.first.size()==n-1 && i.second.size()==0){
               return c; 
            }
            c++;
        }
        return -1;
    }
};