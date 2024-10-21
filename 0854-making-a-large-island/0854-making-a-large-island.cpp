class Solution {
public:
bool ispos(int n,pair<int,int>& p){
    int i=p.first;
    int j=p.second;
    if(i>=0 && j>=0 && i<n && j<n){
        return true;
    }
    return false;
}
pair<int,int> find(vector<vector<pair<int,int>>>& parent,pair<int,int> p){
    if(parent[p.first][p.second]==p){
        return p;
    }
    parent[p.first][p.second]=find(parent,parent[p.first][p.second]);
    return parent[p.first][p.second];
}
void join(vector<vector<pair<int,int>>>& parent,pair<int,int> p1,pair<int,int> p2,vector<vector<int>>& size){
    p1=find(parent,p1);
    p2=find(parent,p2);
    if(p1==p2){
        return;
    }
    if(size[p1.first][p1.second]>size[p2.first][p2.second]){
        swap(p1,p2);
    }
    size[p2.first][p2.second]+=size[p1.first][p1.second];
    parent[p1.first][p1.second]=p2;
}

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n));
        vector<vector<int>> size(n,vector<int> (n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                parent[i][j]=make_pair(i,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                pair<int,int> p=make_pair(i,j);
                vector<pair<int,int>> prs={make_pair(i-1,j),make_pair(i+1,j),make_pair(i,j-1),make_pair(i,j+1)};
                for(auto it:prs){
                    if(ispos(n,it) && grid[it.first][it.second]==1){
                        join(parent,p,it,size);
                    }
                }
            }
        }

        pair<int,int> ppp=find(parent,make_pair(0,0));
        int mxx=size[ppp.first][ppp.second];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1) continue;
                // pair<int,int> p=make_pair(i,j);
                // vector<vector<pair<int,int>>> parent1=parent;
                // vector<vector<int>> size1=size;
                // vector<pair<int,int>> prs={make_pair(i-1,j),make_pair(i+1,j),make_pair(i,j-1),make_pair(i,j+1)};

                // for(auto it:prs){
                //     if(ispos(grid.size(),it) && grid[it.first][it.second]==1){
                //     join(parent,p,it,size);
                //     pair<int,int> pp=find(parent,it);
                //     mxx=max(mxx,size[pp.first][pp.second]);
                //     }
                // }
                // parent=parent1;
                // size=size1;
                set<vector<int>> sett;
                vector<pair<int,int>> prs={make_pair(i-1,j),make_pair(i+1,j),make_pair(i,j-1),make_pair(i,j+1)};
                int ans=1;
                for(auto it:prs){
                    if(!ispos(n,it) || grid[it.first][it.second]==0){continue;}
                    pair<int,int> prtt=find(parent,it);
                    if(sett.find({prtt.first,prtt.second})==sett.end()){
                    ans+=size[prtt.first][prtt.second];
                    sett.insert({prtt.first,prtt.second});}
                }
                mxx=max(mxx,ans);
            }
        }
        return mxx;
    }
};