class Solution {
public:
    bool canCross(vector<int>& nums) {
      unordered_map<int,unordered_set<int>> dp;
      int c=0;
      for(auto it:nums){
        if(c==0){
            c++;
            dp[nums[0]+1].insert(1);
            continue;
        }
        for(auto jt:dp[it]){
            if(find(nums.begin(), nums.end(), it+jt) != nums.end()) dp[it+jt].insert(jt);
            if(jt!=1 && find(nums.begin(), nums.end(), it+jt-1) != nums.end()) dp[it+jt-1].insert(jt-1);
            if(find(nums.begin(), nums.end(), it+jt+1) != nums.end()) dp[it+jt+1].insert(jt+1);
        }
      }  
      if(dp[nums[nums.size()-1]].size()==0) return 0;
      return 1;
    }
};