class Solution {
public:
int stt(string s){
    int a=(s[0]-'0')*10+(s[1]-'0');
    int b=(s[3]-'0')*10+(s[4]-'0');
    return a*60+b;
}
    int findMinDifference(vector<string>& times) {
        vector<int> nums;
        for(int i=0;i<times.size();i++){
            nums.push_back(stt(times[i]));
            
            nums.push_back(1440+stt(times[i]));
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        int ans=min(abs(nums[0]-nums[nums.size()-1]),abs(nums[nums.size()-1]-nums[0]));
       
        for(int i=1;i<nums.size()-1;i++){
            ans=min(ans,min(min(abs(nums[i]-nums[i-1]),abs(nums[i-1]-nums[i])),min(abs(nums[i]-nums[i+1]),abs(nums[i+1]-nums[i]))));
        }
        return ans;
    }
};