class Solution {
public:

bool ispos(vector<vector<char>>& board,int i,int j){
    if(i>=0 && j>=0 && i<board.size() && j<board[0].size()){
        return true;
    }
    return false;
}

void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,vector<int>& drow,vector<int>& dcol,bool& b){
    for(int a=0;a<drow.size();a++){
        
        if(ispos(board,i+drow[a],j+dcol[a]) && board[i+drow[a]][j+dcol[a]]=='O' && visited[i+drow[a]][j+dcol[a]]==0){
            if(i+drow[a]==0 || j+dcol[a]==0 || j+dcol[a]==board[0].size()-1 || i+drow[a]==board.size()-1){
                b=true;
                return;
            }
            visited[i+drow[a]][j+dcol[a]]=1;
            board[i+drow[a]][j+dcol[a]]='X';
            dfs(board,visited,i+drow[a],j+dcol[a],drow,dcol,b);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        vector<int> drow={-1,+1,0,0};
        vector<int> dcol={0,0,-1,+1};
        vector<bool> v(board[0].size(),0);
        vector<vector<bool>> visited(board.size(),v);
        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[i].size()-1;j++){
                if(board[i][j]=='O'  && visited[i][j]==0){
                    vector<vector<char>> boa=board;
                    bool b=false;
                    visited[i][j]=1;
                    board[i][j]='X';
                    dfs(board,visited,i,j,drow,dcol,b);
                    if(b==true){
                        board=boa;
                        continue;
                    }
                }
            }
        }
    }
};