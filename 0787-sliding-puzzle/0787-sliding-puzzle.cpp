class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        vector<vector<int>> desired(2,vector<int>(3));
        desired[0][0]=1;
        desired[0][1]=2;
        desired[0][2]=3;
        desired[1][0]=4;
        desired[1][1]=5;
        desired[1][2]=0;

        set<vector<vector<int>>> sett;
        int m=0;
        sett.insert(board);
        if(board==desired) return m;
        queue<pair<vector<vector<int>>,int>> q;
        q.push(make_pair(board,m));
        while(!q.empty()){
            int r=-1;
            int c=-1;
            board=q.front().first;
            m=q.front().second;
            q.pop();
            m++;
            for(int i=0;i<6;i++){
                if(board[i/3][i%3]==0){r=i/3; c=i%3;}
            }
            vector<int> drow={+1,-1,0,0};
            vector<int> dcol={0,0,-1,+1};
            for(int k=0;k<4;k++){
                if(r+drow[k]>=0 && r+drow[k]<2 && c+dcol[k]>=0 && c+dcol[k]<3) {
                    swap(board[r][c],board[r+drow[k]][c+dcol[k]]);
                    if(board==desired) return m;
                    if(sett.find(board)==sett.end()) {                       
                    q.push(make_pair(board,m));
                    sett.insert(board);
                    }
                    swap(board[r][c],board[r+drow[k]][c+dcol[k]]);
                }
            }
        }
        return -1;
    }
};







