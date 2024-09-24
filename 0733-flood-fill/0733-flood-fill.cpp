class Solution {
public:
bool ispos(vector<vector<int>> image,int i,int j,int c){
    if(((i>=0 && i<image.size()) && (j>=0 && j<image[i].size())) && (image[i][j]==c)){
        return true;
    }
    return false;
}

void floodfill(int i,int j,vector<vector<int>>& image,int clr){
    queue<pair<int,int>> q;
    int clr0=image[i][j];
    image[i][j]=clr;
    q.push({i,j});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        cout<<r<<" "<<c<<endl;
        if(ispos(image,r+1,c,clr0)){
            q.push({r+1,c});
            image[r+1][c]=clr;
        }
        if(ispos(image,r-1,c,clr0)){
            q.push({r-1,c});
            image[r-1][c]=clr;
        }
        if(ispos(image,r,c+1,clr0)){
            q.push({r,c+1});
            image[r][c+1]=clr;
        }
        if(ispos(image,r,c-1,clr0)){
            q.push({r,c-1});
            image[r][c-1]=clr;
        }
        q.pop();
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        floodfill(sr,sc,image,color);
        return image;
    }
};