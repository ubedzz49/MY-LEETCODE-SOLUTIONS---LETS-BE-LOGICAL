class Solution {
public:

bool ispos(vector<vector<int>>& grid,int i,int j){
    if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()){
        return true;
    }
    return false;
}

    int numEnclaves(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=-1; 
            }
            if( grid[i][ grid[0].size()-1]==1){
            q.push({i,static_cast<int> (grid[0].size()-1)});
            grid[i][ grid[0].size()-1]=-1;
            }
        }
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]==1){
            q.push({0,j});
            grid[0][j]=-1;
            }
            if(grid[grid.size()-1][j]==1){
            q.push({static_cast<int>(grid.size())-1,j});
            grid[grid.size()-1][j]=-1;
            }
        }
        vector<int> drow={-1,+1,0,0};
        vector<int> dcol={0,0,-1,+1};
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            q.pop();
            for(int a=0;a<4;a++){
                if(ispos(grid,i+drow[a],j+dcol[a]) && grid[i+drow[a]][j+dcol[a]]==1){
                    grid[i+drow[a]][j+dcol[a]]=-1;
                    q.push({i+drow[a],j+dcol[a]});
                }
            }
        }
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};