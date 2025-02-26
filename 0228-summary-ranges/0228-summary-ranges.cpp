class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        int st=nums[0];
        int en=nums[0];
        vector<string> ans;
        for(int i=1;i<nums.size();i++){
            int it=nums[i];
            if(it==en+1) en++;
            else{
                if(st==en) ans.push_back(to_string(st));
                else ans.push_back(to_string(st)+"->"+to_string(en));
                st=it;;
                en=it;
            }
        }
        if(st==en) ans.push_back(to_string(st));
        else ans.push_back(to_string(st)+"->"+to_string(en));
        return ans;
    }
};