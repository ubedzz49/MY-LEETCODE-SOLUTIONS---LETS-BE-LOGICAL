class Solution {
public:

bool isend(vector<vector<int>> grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            int i1=i-1;
            int i2=i+1;
            int j1=j-1;
            int j2=j+1;
            if(i1>=0 && grid[i1][j]==1 && grid[i][j]==2){
                return false;
            }
            if(j1>=0 && grid[i][j1]==1 && grid[i][j]==2){
                return false;
            }
            if(i2<grid.size() && grid[i2][j]==1 && grid[i][j]==2){
                return false;
            }
            if(j2<grid[0].size() && grid[i][j2]==1 && grid[i][j]==2){
                return false;
            }
        }
    }
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
int co=0;int c1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    co=1;
                }
                if(grid[i][j]==1){
                    c1=1;
                }
            }
        }
        if(c1==0){
    return 0;
}
if(co==0){
    return -1;
}

if(isend(grid)==1){
    for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return 0;
}

        int c=0;
        while(isend(grid)==0){
            c=c+1;
            vector<vector<int>> grid1=grid;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
            int i1=i-1;
            int i2=i+1;
            int j1=j-1;
            int j2=j+1;
            if(i1>=0 && grid[i1][j]==1 && grid[i][j]==2){
                if(grid[i1][j]!=0){
                    grid1[i1][j]=2;
                }
            }
            if(j1>=0 && grid[i][j1]==1 && grid[i][j]==2){
                if(grid[i][j1]!=0){
                    grid1[i][j1]=2;
                }
            }
            if(i2<grid.size() && grid[i2][j]==1 && grid[i][j]==2){
                if(grid[i2][j]!=0){
                    grid1[i2][j]=2;
                }
            }
            if(j2<grid[0].size() && grid[i][j2]==1 && grid[i][j]==2){
                if(grid[i][j2]!=0){
                    grid1[i][j2]=2;
                }
            }
                }
            }
            grid=grid1;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return c;
    }
};