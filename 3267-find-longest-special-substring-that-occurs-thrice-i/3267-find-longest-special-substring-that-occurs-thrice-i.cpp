class Solution {
public:
    
    
    bool fn(string s){
        int n=s.size();
        char firstChar=s[0];
        for(int i=0;i<n;i++){
            if(s[i]!=firstChar){
                return false;
            }
        }
        return true;
    }
    
    int solve(int i,string s,vector<int>&dp,unordered_map<string,int>&mp){
        int n=s.size();
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        string currSubstring;
        int maxLength=0;
        
        for(int j=i;j<n;j++){
            currSubstring+=s[j];
            
            if(fn(currSubstring)==true){
                mp[currSubstring]++;
                if(mp[currSubstring]>=3){
                    maxLength=max(maxLength,(int)currSubstring.size());// int ya maxLength ko size_t se initialize kro,, bec string size size_t mein hota hai, so max ke saath use krne ke liy, (int) use krnahota haiii
                }
            }
            else{
                break;
            }
        }
        
        dp[i]=max(maxLength,solve(i+1,s,dp,mp));
        return dp[i];
    }
    
    
    int maximumLength(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,int>mp;
        
        int ans=solve(0,s,dp,mp);
        return ans==0?-1:ans;
    }
};