class Solution {
public:

// //MEMOIZATION
// int memo(vector<vector<long long>>& dp,vector<vector<int>>& nums,int i,int j){
//    // if(nums[i][j]==1) return 0;
//     if(i==nums.size()-1 && j==nums[0].size()-1){return dp[i][j]=1;}
//     long long ans=0;
//     if(i+1<nums.size() && nums[i+1][j]!=1){
//         if(dp[i+1][j]==-1) ans+=memo(dp,nums,i+1,j);
//         else{ans+=dp[i+1][j];}
//     }
//     if(j+1<nums[0].size() && nums[i][j+1]!=1){
//         if(dp[i][j+1]==-1) ans+=memo(dp,nums,i,j+1);
//         else{ans+=dp[i+1][j];}
//     }
//     return dp[i][j]=ans;
// }


    int uniquePathsWithObstacles(vector<vector<int>>& nums) {

        // //MEMOIZATION
        // vector<vector<long long>> dp(nums.size(),vector<long long>(nums[0].size(),-1));
        // if(nums[nums.size()-1][nums[0].size()-1]==0 && nums[0][0]==0){
        //     dp[nums.size()-1][nums[0].size()-1]==1;
        //     long long ans=memo(dp,nums,0,0);
        //     return ans;
        // }
        // else return 0;


        // //TABULATION
        // int r=nums.size();
        // int c=nums[0].size();
        // vector<vector<long long>> dp(r,vector<long long>(c,0));
        // if(nums[r-1][c-1]==0) dp[r-1][c-1]=1;
        // else{return 0;}
        // for(int j=c-1;j>=0;j--){
        //     for(int i=r-1;i>=0;i--){
        //         if(i-1>=0 && nums[i-1][j]==0) dp[i-1][j]+=dp[i][j];
        //         if(j-1>=0 && nums[i][j-1]==0) dp[i][j-1]+=dp[i][j];
        //     }
        // }
        // return dp[0][0];





        //SPACE OPTIMIZATION WITH TABULATION
        if(nums[nums.size()-1][nums[0].size()-1]==1 || nums[0][0]==1) return 0;
        int r=nums.size();
        int c=nums[0].size();
        vector<long long> curr(r,0);
        curr[r-1]=1;
        for(int j=c-1;j>=0;j--){
            vector<long long> next(r,0);
            for(int i=r-1;i>=0;i--){
                if(i>0 && nums[i-1][j]==0) curr[i-1]+=curr[i];
                if(j>0 && nums[i][j-1]==0) next[i]+=curr[i];
            }
            if(j==0) return curr[0];
            curr=next;
        }
        return 0;
    }
};