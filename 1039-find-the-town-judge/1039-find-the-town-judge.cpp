class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
      vector<pair<int,int>> t(n+1,{0,0});
      for(int i=0;i<trust.size();i++){
        t[trust[i][0]].first+=1;
        t[trust[i][1]].second+=1;
      }
      for(int i=0;i<t.size();i++){
        cout<<i<<"->"<<t[i].first<<" "<<t[i].second<<endl;
        if(t[i].first==0 && t[i].second==n-1){
            return i;
        }
      }
        return -1;
    }
};