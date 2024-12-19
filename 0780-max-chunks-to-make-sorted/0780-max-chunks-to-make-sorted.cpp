class Solution {
public:
    int dp[11];

    int solve(int idx,vector<int>& arr)
    {
        if(idx>=arr.size())
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int ans = INT_MIN;
        vector<int> tmp;
        for(int i=0;i+idx<arr.size();i++)
        {
            tmp.push_back(arr[idx+i]);
            sort(tmp.begin(),tmp.end());
            int flg = 0;
            int p = idx;
            for(auto &j:tmp)
            {
                if(j!=p)
                {
                    flg = 1;
                    break;
                }
                p++;
            }
            if(!flg)
            {
                ans = max(ans,1+solve(idx+i+1,arr));
            }
        }
        return dp[idx] = ans;
    }
    int maxChunksToSorted(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr);
    }
};