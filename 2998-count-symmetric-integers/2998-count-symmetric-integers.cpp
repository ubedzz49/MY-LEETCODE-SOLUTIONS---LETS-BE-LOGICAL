class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
       int ans=0;
       for(int i=low;i<=high;i++){
        int n=i;
        vector<int> a;
        while(n>0){
            a.push_back(n%10);
            n/=10;
        }
        if(a.size()%2!=0) continue;
        int sm=0;
        for(int it=0;it<a.size();it++){
            if(it<a.size()/2) sm+=a[it];
            else sm-=a[it];
        }
        if(sm==0) ans++;
       } 
       return ans;
    }
};