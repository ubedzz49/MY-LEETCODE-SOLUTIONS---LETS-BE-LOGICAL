class Solution {
    public:
        int solve(int idx,int n,vector<int>& nums,int curr,int maxi)
            {
                    if(idx>=n)
                            {
                                        return (curr==maxi) ? 1 : 0;
                                                }

                                                        // take
                                                                int take=solve(idx+1,n,nums,curr | nums[idx],maxi);

                                                                        // not take
                                                                                int notTake=solve(idx+1,n,nums,curr,maxi);
                                                                                        
                                                                                                return take+notTake;
                                                                                                    }

                                                                                                        int countMaxOrSubsets(vector<int>& nums) {
                                                                                                                int n=nums.size();
                                                                                                                        int maxi=0;
                                                                                                                                
                                                                                                                                        for(auto it:nums)
                                                                                                                                                maxi |= it;

                                                                                                                                                        return solve(0,n,nums,0,maxi);
                                                                                                                                                            }
                                                                     };
