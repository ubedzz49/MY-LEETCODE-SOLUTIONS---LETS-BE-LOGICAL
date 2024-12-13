class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<bool> vis(nums.size(),0);
        int n=nums.size();
        long long ans=0;
        while(n>0){
            vector<int>v= pq.top();
            pq.pop();
            if(vis[v[1]]==0){
                vis[v[1]]=1;
                n--;
                ans+=v[0];
                if(v[1]+1<nums.size() && vis[v[1]+1]==0){
                    vis[v[1]+1]=1;
                    n--;
                }
                if(v[1]-1>=0 && vis[v[1]-1]==0){
                    vis[v[1]-1]=1;
                    n--;
                }
            }
        }
        return ans;
    }
};