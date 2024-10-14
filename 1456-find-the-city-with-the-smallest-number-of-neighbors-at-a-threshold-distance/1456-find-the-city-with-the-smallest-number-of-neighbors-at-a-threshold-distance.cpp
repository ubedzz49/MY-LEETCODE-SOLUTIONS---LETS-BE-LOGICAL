class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        
for(int i=0;i<n;i++){
        dist[i][i]=0;
        }

        for(int city=0;city<n;city++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][city]!=INT_MAX && dist[city][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j], dist[i][city]+dist[city][j]);
                    }
                }
            }
        }
        int index=-1;
        int count=INT_MAX;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=th){
                    c++;
                }
            }
            if(count>=c){
                index=i;
                count=c;
            }
        }
       return index;
    }
};