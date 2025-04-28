class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int s = 0;
        long long sum = 0, ct = 0; 
        for(int e = 0; e < nums.size(); e++){
            sum += nums[e]; 
            while(sum * (e-s+1) >= k){
                sum -= nums[s];
                s++;
            } 
            ct += (e-s+1);
        } 
        return ct;
    }
};