class Solution {
public:
vector<bool> tobin(int n){
    vector<bool> bin;
    while(n>0){
        bin.push_back(n%2);
        n/=2;
    }
   // reverse(bin.begin(),bin.end());
    return bin;
}
    int minBitFlips(int s, int g) {
        vector<bool> m=tobin(max(s,g));
        vector<bool> n=tobin(min(s,g));
        int ans=0;
        for(int i=0;i<m.size();i++){
            if(i<n.size()){
                 cout<<m[i]<<n[i]<<i<<endl;
            }else{
                cout<<m[i]<<endl;
            }
           
            if(i<n.size() && m[i]!=n[i]){
                ans++;
            }
            if(i>=n.size() && m[i]==1){
                ans++;
            }
        }
        return ans;
    }
};