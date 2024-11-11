class Solution {
public:
bool isprime(int n){
    if(n<2) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
    bool primeSubOperation(vector<int>& nums) {
        for(int k=0;k<nums.size();k++){
            int it=nums[k];
            int n=0;
            for(int i=it-1;i>-1;i--){
                if(i==1) continue;
                if(isprime(i) || i==0){ 
                    n=i; 
                    //cout<<k;

                    if(k==0 || nums[k-1]<it-n) break;
                }
            }
            it-=n;
            nums[k]=it;
            //cout<<it;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]) return false;
        }
        return true;
    }
};