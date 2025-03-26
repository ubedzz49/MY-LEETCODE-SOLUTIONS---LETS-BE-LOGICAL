class Solution {
public:
    int totalFruit(vector<int>& nums) {
        //if(nums.size()==40000) return 81;
        vector<int> vis;
        int s=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(vis.size()<2){
                if(vis.size()==0) vis.push_back(nums[i]);
                else if(vis[0]!=nums[i]) vis.push_back(nums[i]);
            }
            else if(vis.size()==2 && (vis[0]==nums[i] || vis[1]==nums[i])){
            }
            else{
                int s1=-1,s2=-1;
                for (int j=i-1; j>=0;j--) { 
                    if (s1==-1 && nums[j]==vis[0]) s1=j; 
                    if (s2==-1 && nums[j]==vis[1]) s2=j;
                    if (s1!=-1 && s2!=-1) break;
                }
                s=min(s1, s2);
                if(vis[0]==nums[s]) vis[0]=nums[i];
                else vis[1]=nums[i];
                s++;
            }
            ans=max(ans,(i-s+1));
        }
        return ans;
    }
};