class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const unsigned int p=pow(10,9)+7;
        vector<int> dp={1,0,0};
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            vector<int> dp1=dp;
            if(arr[i]&1){
                dp[1]=dp1[2]+dp1[0];
                dp[2]=dp1[1];
            }
            else{
                dp[2]=dp1[0]+dp1[2];
                dp[1]=dp1[1];
            }
            ans+=(dp[1]);
        }
        return ans%p;
    }
};