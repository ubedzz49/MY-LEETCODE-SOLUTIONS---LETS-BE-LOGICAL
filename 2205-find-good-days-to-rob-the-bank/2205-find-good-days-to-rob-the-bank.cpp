class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> bef(n,0);
        vector<int> af(n,0);
        int c=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                bef[i]=0;
                c=1;
            }
            else{
                bef[i]=c;
                c++;
            }
            //cout<<i<<" "<<bef[i]<<endl;
        }
        //cout<<"----"<<endl;
        c=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                af[i]=0;
                c=1;
            }
            else{
                af[i]=c;
                c++;
            }
            //cout<<i<<" "<<af[i]<<endl;
        }
        vector<int> ans;
        for(int i=k;i<n-k;i++){
            if(bef[i]>=k && af[i]>=k) ans.push_back(i);
        }
        return ans;
    }
};