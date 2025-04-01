class Solution {
public:
    int characterReplacement(string str, int k) {
        int ans=0;
        for(int j=0;j<26;j++){
            int nn='A'+j;
            char it=nn;

            int c=0;
            int s=0;
            for(int i=0;i<str.size();i++){
                if(str[i]!=it) c++;
                if(c>k){
                    while(c>k){
                        if(str[s]!=it) c--;
                        s++;
                    }
                }
                
                ans=max(ans,(i-s+1));
                //cout<<ans<<" "<<i<<" "<<s<<endl;
            }
        }
        return ans;
    }
};