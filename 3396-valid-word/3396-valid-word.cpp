class Solution {
public:
    bool isValid(string nums) {
       if(nums.size()<3){
        return false;
       }
       int v=0;
       int c=0;
       for(int i=0;i<nums.size();i++){
        int n=nums[i];
        if(!((n<=90 && n>=65) || (n>=97 && n<=122) || (n<=57 && n>=48))){
            return false;
        }
        if(((n<=90 && n>=65) || (n>=97 && n<=122))){
            if(nums[i]=='a' || nums[i]=='e' || nums[i]=='i' || nums[i]=='o' || nums[i]=='u' || nums[i]=='A' || nums[i]=='E' || nums[i]=='I' || nums[i]=='O' || nums[i]=='U'){
                v++;
            }else{
                c++;
            }
        }
       }
       if(v>0 && c>0){
        return true;
       }
        return false;
    }
};