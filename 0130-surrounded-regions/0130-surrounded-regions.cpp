class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};
void dfx(pair<int,int> p,vector<vector<char>>& board){
    int m=board.size();
    int n=board[0].size();
        board[p.first][p.second]='#';
        for(int i=0;i<4;i++){
            int row=p.first+drow[i];
            int col=p.second+dcol[i];
            if(row>=0 && row<m && col>=0 && col<n&& board[row][col]=='O'){
                dfx({row,col},board);
            }
        }
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfx({i,0},board);
            }
            if(board[i][n-1]=='O'){
                dfx({i,n-1},board);
            }
        }
         for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfx({0,j},board);
            }
             if(board[m-1][j]=='O'){
                dfx({m-1,j},board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};