class Solution {
public:
pair<int,int> fn(int n,int d){
    int r=(n-1)/d;
    int c=(n-1)%d;
    if(r&1) c=d-1-c;
    r=d-1-r;
    return {r,c};
}
    int snakesAndLadders(vector<vector<int>>& board) {
    
        int n=board.size();
        vector<int> dp(n*n+1,INT_MAX);
        queue<int> q;
        dp[1]=0;
        q.push(1);
        while(!q.empty()){
            int d=q.front();
            q.pop();
            pair<int,int> p=fn(d,n);
                for(int i=1;i<=6 && d+i<=n*n;i++){
                    if(board[fn(d+i,n).first][fn(d+i,n).second]!=-1){
                        if(dp[board[fn(d+i,n).first][fn(d+i,n).second]]>dp[d]+1){
                            dp[board[fn(d+i,n).first][fn(d+i,n).second]]=dp[d]+1;
                            q.push(board[fn(d+i,n).first][fn(d+i,n).second]);
                        }
                    }
                    else if(dp[d+i]>dp[d]+1){
                        dp[d+i]=dp[d]+1;
                        q.push(d+i);
                    }
                }
        }
        if(dp[n*n]==INT_MAX) return -1;
       return dp[n*n]; 
    }
};