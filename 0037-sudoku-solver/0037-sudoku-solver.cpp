class Solution {
public:
bool isvalid(int row,int col,vector<vector<char>>& board,int k){
    for(int i=0;i<9;i++){
        if(board[i][col]==char(k+'0')){
            return false;
        }
        if(board[row][i]==char(k+'0')){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==char(k+'0')){
            return false;
        }
    }
    return true;
}
bool sudoku(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isvalid(i,j,board,k)){
                            board[i][j]=char(k+'0');
                            if(sudoku(board)==true){return true;}
                            board[i][j]='.';
                            }
                    }
                    return false;
                }
            }
        }
        return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
        //return board;
    }
};