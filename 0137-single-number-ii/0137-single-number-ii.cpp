class Solution {
public:
    int singleNumber(vector<int>& nums) {
      vector<int> no(33,0);
      int ng=0;
      for(auto it:nums){
        if(it==INT_MIN){
            no[31]++;
            ng++;
            continue;
        }
        if(it<0) ng++;
        it=abs(it);
        for(int j=0;j<32;j++){
            if(it&(1<<j)) no[j]++;
        }
      }
      for(auto it:no) cout<<it<<" ";
      long long ans=0;
      int f=1;
      if(ng%3) f=-1;
      for(int i=0;i<33;i++) if(no[i]%3) ans+=((pow(2,i))*f);
      return ans;
    }
};