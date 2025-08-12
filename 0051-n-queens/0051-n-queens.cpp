class Solution {
public:
bool issafe(int row,int col,vector<string> &board){
    int orirow=row;
    int oricol=col;
    for(int j=0;j<board.size();j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    row=orirow;
    col=oricol;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;col--;
    }
    row=orirow;
    col=oricol;
    while(row<board.size() && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board)){
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //vector<string> board(n, string(n, '.'));
        solve(0,ans,board,n);
        return ans;
    }
};