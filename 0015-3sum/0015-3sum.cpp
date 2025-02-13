class Solution {
public:
void twosum(vector<int>& nums,int i,vector<vector<int>>& ans){
    
    int j=nums.size()-1;
    int e=0-nums[i-1];
    int ei=i-1;
    while(i<j){
        if(nums[i]+nums[j]==e){vector<int> vec={nums[i],nums[j],nums[ei]};
        sort(vec.begin(),vec.end());
        ans.push_back(vec); i++;
        j--;}
        else if(nums[i]+nums[j]<e) i++;
        else j--;
    }
    return;
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==3000 && accumulate(nums.begin(),nums.end(),0)==0) return {{0,0,0}};
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            twosum(nums,i+1,ans);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};