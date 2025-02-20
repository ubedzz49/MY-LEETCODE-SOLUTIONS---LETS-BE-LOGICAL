class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
           unordered_map<char,bool> vis;
           int n=0;
           for(int j=i;j<s.size();j++){
            if(vis[s[j]]==0) n++;
            else{
                ans=max(ans,n);
                break;
            }
            ans=max(ans,n);
            vis[s[j]]=1;
           }
        }
        return ans;
    }
};