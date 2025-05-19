class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         if(nums[0]+nums[1]<=nums[2]){
            return "none";
        }
        int c=0;
        for(int i=0;i<2;i++){
            if(nums[i]==nums[i+1]){
                c++;
            }
        }
        string s;
        if(c==2){
            s="equilateral";
        }
        if(c==1){
            s="isosceles";
        }
        if(c==0){
            s="scalene";
        }
        return s;
    }
};