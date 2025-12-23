class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c-'0'>=0&&c-'0'<=9){
                for(int row=0;row<9;row++){
                    if(row!=i){
                        if(board[row][j]==c){return false;}
                    }
                }
                for(int col=0;col<9;col++){
                    if(col!=j){
                        if(board[i][col]==c){return false;}
                    }
                }
                int rowbox=(i/3)*3;
                int colbox=(j/3)*3;
                for(int row=rowbox;row<rowbox+3;row++){
                    for(int col=colbox;col<colbox+3;col++){
                    if(!(row==i&&col==j)){
                        if(board[row][col]==c){return false;}
                    }
                    }
                }
            }
            }
        }
        return true;
    }
};