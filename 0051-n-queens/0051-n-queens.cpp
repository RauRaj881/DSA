class Solution {
public:
vector<vector<string>> ans;
bool issafe(int row,int col,vector<string>& board,int n){
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){return false;}
    }
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){return false;}
    }
    int i=row,j=col;
    while(i>=0&&j>=0){
        if(board[i][j]=='Q'){return false;}
        i--;j--;
    }
    i=row,j=col;
    while(i>=0&&j<n){
        if(board[i][j]=='Q'){return false;}
        i--;j++;
    }
    return true;
}
void f(int row,int n,vector<string>& board){
    if(row==n){ans.push_back(board);return;}
    for(int col=0;col<n;col++){
        if(issafe(row,col,board,n)){
            board[row][col]='Q';
            f(row+1,n,board);
            board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n){
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=string(n,'.');
        }
        f(0,n,board);
        return ans;
    }
};