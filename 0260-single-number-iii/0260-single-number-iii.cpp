class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto it:nums) x=x^it;
        int ind=-1;
        for(int i=0;i<32;i++) if(x&(1<<i)){
            ind=i;
            break;
        }
        int g1=0;
        int g2=0;
        for(auto it:nums){
            if(it&(1<<ind)) g1=g1^it;
            else g2=g2^it;
        }
        return {g1,g2};
    }
};