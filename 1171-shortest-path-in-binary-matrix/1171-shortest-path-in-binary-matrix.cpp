class Solution {
public:
bool ispos(vector<vector<int>>& grid,int& r,int& c){
    if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==0){
        return true;
    }
    return false;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        set<vector<int>> sett;
        vector<int> sp1(grid[0].size(),INT_MAX);
        vector<vector<int>> sp(grid.size(),sp1);
        if(grid.size()==0 || grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1){
            return -1;
        }
        if(grid.size()==1){
            return 1;
        }
        sp[0][0]=0;
        sett.insert({1,0,0});
        vector<int> dr={+1,-1,0,0,-1,-1,+1,+1};
        vector<int> dc={0,0,+1,-1,-1,+1,-1,+1};
        while(!sett.empty()){
            auto v=*sett.begin();
            int r=v[1],c=v[2],dist=v[0];
            sett.erase({dist,r,c});
            for(int i=0;i<8;i++){
                int drow=r+dr[i];
                int dcol=c+dc[i];
                if(ispos(grid,drow,dcol) && dist+1<sp[drow][dcol]){
                    if(sp[drow][dcol]!=INT_MAX){
                        sett.erase({sp[drow][dcol],drow,dcol});
                    }
                    sp[drow][dcol]=dist+1;
                    sett.insert({dist+1,drow,dcol});
                }
            }
        }
        return (sp[grid.size()-1][grid[0].size()-1]!=INT_MAX)? sp[grid.size()-1][grid[0].size()-1] : -1;
    }
};