class Solution {
public:

    vector<int> closestPrimes(int left, int right) {
       
vector<bool> mpp(right+1,1);
mpp[0]=0;
mpp[1]=0;
for(int i=2;i<right;i++){
    if(mpp[i]==1){
        if(i*i>right) break;
        for(int j=i*i;j<=right;j+=i){
            mpp[j]=0;
        }
    }
}

        vector<int> ans={-1,-1};
        int l=-1,c=0;
        for(int i=left;i<=right;i++){
            if(mpp[i]==1) {
               
                if(l!=-1){
                    if(c>1 && i-l<ans[1]-ans[0]) ans={l,i};
                }
                l=i;
                c++;
                if(c<=2) ans[c-1]=i;
            }
        }
        if(c<2) return {-1,-1};
        return ans;
    }
};