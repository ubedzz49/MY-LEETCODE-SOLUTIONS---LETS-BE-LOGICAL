class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        vector<bool> visited(nums.size(),0);
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            if(nums[ind]==0) return true;
            if(ind-nums[ind]>=0 && visited[ind-nums[ind]]==0) {
                q.push(ind-nums[ind]);
                visited[ind-nums[ind]]=1;
            }
            if(ind+nums[ind]<nums.size() && visited[ind+nums[ind]]==0) {
                q.push(ind+nums[ind]);
                visited[ind+nums[ind]]=1;
            }
        }
        return false;
    }
};