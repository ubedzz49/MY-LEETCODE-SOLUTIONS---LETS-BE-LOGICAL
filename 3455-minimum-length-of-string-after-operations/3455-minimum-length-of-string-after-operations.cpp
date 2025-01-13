class Solution {
public:
    int minimumLength(string s) {
        vector<pair<int,int>> lr(s.size(),make_pair(0,0));
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            lr[i].first=mpp[s[i]];
            mpp[s[i]]++;
        }
        for(int i=s.size()-1;i>=0;i--){
            lr[i].second=mpp[s[i]]-lr[i].first-1;
            mpp[s[i]]--;
        }
        
        for(int i=0;i<s.size();i++){
            int sum=lr[i].first+lr[i].second;
            mpp[s[i]]=max(mpp[s[i]],sum-(sum%2));
        }
        int ans=0;
        for(auto it:mpp) ans+=it.second;
        return s.size()-ans;
    }
};