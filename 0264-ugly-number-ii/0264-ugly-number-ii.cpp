// class Solution {
// public:
// void frm(vector<int> & nums,int n,int num){
//     nums.push_back(n);
//     if(n>=num){
//         return;
//     }
//     frm(nums,n*2,num);
//     frm(nums,n*3,num);
//     frm(nums,n*5,num);
// }
// void prm(vector<int>& nums,int n){
//     for(int i=2;i<nums.size();i++){
//         bool b=true;
//         for(int j=2;j<i;j++){
//             if(j%i==0){
//                 b=false;
//             }
//         }
//         if(b==true){
//             nums.push_back(i);
//         }
//     }
// }
//     int nthUglyNumber(int n) {
//         vector<int> nums;
//         frm(nums,1,1651);
//         prm(nums,1651);
//     sort(nums.begin(),nums.end());
//    nums.erase(unique(nums.begin(),nums.end()),nums.end());
   
//     return (nums[n-1]);
//     }
// };
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            int next = min(min(next2, next3), next5);
            ugly[i] = next;
            if (next == next2) i2++;
            if (next == next3) i3++;
            if (next == next5) i5++;
        }
        return ugly[n - 1];
    }
};