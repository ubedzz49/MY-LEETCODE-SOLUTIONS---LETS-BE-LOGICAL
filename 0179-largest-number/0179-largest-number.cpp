bool compare(int a,int b){
    string aa=to_string(a);
    string bb=to_string(b);
    return aa+bb>bb+aa;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        if(nums[0]==0)return "0";
        string a="";
        for(auto i:nums)a+=to_string(i);
        return a;
    }
};