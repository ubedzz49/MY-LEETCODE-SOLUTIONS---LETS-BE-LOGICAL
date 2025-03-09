class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int br=-1;
        int ans=0;
        for(int i=0;i<k;i++) nums.push_back(nums[i%nums.size()]);
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]) br=i-1;
        }
        if(br==-1) ans++;
        for(int ii=k;ii<nums.size()-1;ii++){
            int i=ii%nums.size();
            if(nums[i]==nums[(ii-1)%nums.size()]) br=ii-1;
            if(ii-k>=br) {ans++; cout<<ii<<" ";}
            cout<<ii<<"  ";
        }
        return ans;
    }
};