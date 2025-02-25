class Solution {
public:


    int numOfSubarrays(vector<int>& arr) {
        const int p= 1e9 +7;
        int od=0;
        int ev=0;
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            int od1=od;
            int ev1=ev;
            if(arr[i]&1){
                od=ev1+1;
                ev=od1;
            }
            else{
                ev=1+ev1;
                od=od1;
            }
            ans+=(od);
        }
        return ans%p;
        
    }
};