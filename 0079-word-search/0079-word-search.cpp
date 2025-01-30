class Solution {
public:
vector<int> dir={-1,+1,0,0};
bool isthere(vector<vector<char>>& board,int i,int j,string word,vector<vector<bool>>& vis,int& ind){
    if(ind==word.size()-1) return true;
    bool b=false;
    for(int ii=0;ii<4;ii++){
        ind++;
        int r=i+dir[ii];
        int c=j+dir[3-ii];
        if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && vis[r][c]==0 && board[r][c]==word[ind]){
            vis[r][c]=1;
            b=b|isthere(board,r,c,word,vis,ind);
            vis[r][c]=0;
        }
        ind--;
    }
    return b;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=word.size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int ind=0;
                vector<vector<bool>> vis(board.size(),vector<bool> (board[0].size(),0));
                vis[i][j]=1;
                if(word[0]==board[i][j] && isthere(board,i,j,word,vis,ind)) return 1;
            }
        }
        
        
        
        return 0;
    }
};