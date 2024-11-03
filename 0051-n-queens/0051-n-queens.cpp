class Solution {
public:
bool ispos(int n,int i,int j){
    if(i>=0 && j>=0 && i<n && j<n) return true;
    return false;
}
void place(vector<string>& curr,int& i,int& j,int& n){
    curr[i][j]='Q';
    for(int it=0;it<n;it++){
        if(ispos(n,it,j)) curr[it][j]='.';
        if(ispos(n,i,it)) curr[i][it]='.';
    }
    for(int it=1;i-it>=0;it++){
        if(ispos(n,i-it,j-it)) curr[i-it][j-it]='.';
        if(ispos(n,i-it,j+it)) curr[i-it][j+it]='.';
    }
    for(int it=1;i+it<n;it++){
        if(ispos(n,i+it,j-it)) curr[i+it][j-it]='.';
        if(ispos(n,i+it,j+it)) curr[i+it][j+it]='.';
    }
    curr[i][j]='Q';
}
void back(vector<vector<string>>& ans,vector<string>& curr,int& i,int& n){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    for(int j=0;j<n;j++){
        if(curr[i][j]==' '){
            vector<string> v=curr;
            place(curr,i,j,n);
            i++;
            back(ans,curr,i,n);
            i--;
            curr=v;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n,string(n,' '));
        int i=0;
        back(ans,curr,i,n);
        return ans;
    }
};