class Solution {
public:
    int maxScore(vector<int>& nums, int k) {

        //TLE SOLUTIOMM 13/40
        // queue<vector<int>> q;
        // int ans=0;
        // q.push({0,0,static_cast<int>(nums.size()-1),k});
        // while(!q.empty()){
        //     int cs=q.front()[0];
        //     int s=q.front()[1];
        //     int e=q.front()[2];
        //     int kk=q.front()[3];
        //     q.pop();
        //     if(kk==0){
        //         ans=max(ans,cs);
        //         continue;
        //     }
        //     if(s<=e){
        //         q.push({cs+nums[s],s+1,e,kk-1});
        //         q.push({cs+nums[e],s,e-1,kk-1});
        //     }
        // }
        // return ans;
        if(k==nums.size()) return accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int ans=sum;
        int ssum=sum;
        sum=0;
        int kk=k-1;
        for(int i=nums.size()-1;i>=nums.size()-k;i--){
            sum+=nums[i];
            ssum-=nums[kk];
            kk--;
            int currsum=sum+ssum;
            ans=max(ans,currsum);
        }
        return ans;
    }
};