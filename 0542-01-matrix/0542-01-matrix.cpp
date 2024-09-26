class Solution {
public:
bool ispos(int i,int j,vector<vector<int>>& mat){
    if(i>=0 && j>=0 && i<mat.size() && j<mat[i].size()){
        return true;
    }
    return false;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<bool> v(mat[0].size(),0);
    vector<vector<bool>> visited(mat.size(),v);  
    vector<int> d(mat[0].size(),0);
    vector<vector<int>> distance(mat.size(),d);
    queue<vector<int>> q;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]==0){
                distance[i][j]=0;
                visited[i][j]=1;
                q.push({i,j,1});
            }
        }
    }
    vector<int> drow={+1,-1,0,0};
    vector<int> dcol={0,0,-1,+1};
    while(!q.empty()){
        int n=q.front()[2];
        int i=q.front()[0];
        int j=q.front()[1];
        q.pop();
        for(int a=0;a<4;a++){
            if(ispos(i+drow[a],j+dcol[a],mat) && visited[i+drow[a]][j+dcol[a]]==0){
                visited[i+drow[a]][j+dcol[a]]=1;
                distance[i+drow[a]][j+dcol[a]]=n;
                q.push({i+drow[a],j+dcol[a],n+1});
            }
        }
    }
    return distance;
    }
};