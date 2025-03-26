class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        unordered_map<char,bool> mpp;
        int ans=0;
        int s=0;
        for(int i=0;i<st.size();i++){
            if(mpp[st[i]]==0){
                mpp[st[i]]=1;
                ans=max(ans,i-s+1);
            }
            else{
                while(st[s]!=st[i]) {mpp[st[s]]=0; s++;}
                s++;
            }
            ans=max(ans,i-s+1);
            
        }
        return ans;
    }
};