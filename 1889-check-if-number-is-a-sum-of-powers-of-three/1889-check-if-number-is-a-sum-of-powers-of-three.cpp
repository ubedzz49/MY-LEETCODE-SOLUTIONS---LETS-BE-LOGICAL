class Solution {
public:
    bool checkPowersOfThree(int n) {
      vector<int> dp;
      dp.push_back(n);
      for(int p=16;p>=0;p--){
        int c=pow(3,p);
        int s=dp.size();
        for(int i=0;i<s;i++){
            if(dp[i]>=c) {
                dp.push_back(dp[i]-c);
                if(dp[i]-c==0) return true;
                }
        }
      }
      return false;
    }
};