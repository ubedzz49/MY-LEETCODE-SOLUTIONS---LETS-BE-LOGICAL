class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> vis(51,0);
        int ans=0;
        for(auto it:nums) vis[it]++;
        for(int i=0;i<=50;i++) if(vis[i]==2) ans=ans^i;
        return ans;
    }
};