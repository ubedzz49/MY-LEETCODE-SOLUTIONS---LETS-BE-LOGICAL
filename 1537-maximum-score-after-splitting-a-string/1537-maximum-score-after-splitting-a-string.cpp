class Solution {
public:
    int maxScore(string s) {
        int z=0,o=0;
        vector<pair<int,int>> pre;
        for(auto it: s){
           
            if(it=='0') z++;
            else o++; pre.push_back(make_pair(z,o));
        }
        int ans=0;
        int i=0;
        for(auto it:pre){
            if(i==s.size()-1) continue;
            ans=max(ans,it.first+o-it.second);
            i++;
        }
        return ans;
    }
};