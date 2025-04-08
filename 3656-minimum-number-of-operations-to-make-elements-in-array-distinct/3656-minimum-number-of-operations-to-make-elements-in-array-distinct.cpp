class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int c=0;
        for(auto it:nums) {
        mpp[it]++;
        if(mpp[it]==2) c++;
        }
        int ans=0;
        if(c==0) return 0;
        for(int i=0;i<nums.size();i+=3){
            ans++;
            if(i+2>=nums.size()) return ans;
            mpp[nums[i]]--;
            if(mpp[nums[i]]==1) c--;
            mpp[nums[i+1]]--;
            if(mpp[nums[i+1]]==1) c--;
            mpp[nums[i+2]]--;
            if(mpp[nums[i+2]]==1) c--;
            if(c==0) return ans;
            for(auto it:mpp) cout<<it.first<<"--"<<it.second<<endl;
            cout<<c<<" "<<nums[i]<<endl;
        }
        return ans;
    }
};