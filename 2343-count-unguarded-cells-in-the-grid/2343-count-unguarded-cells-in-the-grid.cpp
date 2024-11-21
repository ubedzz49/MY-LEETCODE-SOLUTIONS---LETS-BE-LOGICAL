class Solution {
public:
bool ispos(int i,int j,int m,int n,vector<vector<int>>& grid){
    if(i>=0 && j>=0 && i<m && j<n && grid[i][j]!=1 && grid[i][j]!=2){
        return true;
    }
    return false;
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int> (n,-1));
        for(auto it:guards) grid[it[0]][it[1]]=1;
        for(auto it:walls) grid[it[0]][it[1]]=2;
        queue<vector<int>> q;
        vector<int> drow={+1,-1,0,0};
        vector<int> dcol={0,0,-1,+1};
        for(auto it:guards){
            for(int i=0;i<4;i++){
                if(ispos(it[0]+drow[i],it[1]+dcol[i],m,n,grid)){
                    grid[it[0]+drow[i]][it[1]+dcol[i]]=5;
                    q.push({it[0]+drow[i],it[1]+dcol[i],i});
                }
            }
        }

        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            if(ispos(v[0]+drow[v[2]],v[1]+dcol[v[2]],m,n,grid)){
                grid[v[0]+drow[v[2]]][v[1]+dcol[v[2]]]=5;
                 q.push({v[0]+drow[v[2]],v[1]+dcol[v[2]],v[2]});
                 }
        }

        int ans=0;
        for(auto it:grid){
            for(auto jt:it){
                if(jt==-1) ans++;
            }
        }
        return ans;
    }
};