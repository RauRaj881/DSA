class Solution {
public:
int drow[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};
void dfx(pair<int,int> p,vector<vector<char>>& board,vector<vector<int>> &vis){
    int m=board.size();
    int n=board[0].size();
        vis[p.first][p.second]=1;
        for(int i=0;i<4;i++){
            int row=p.first+drow[i];
            int col=p.second+dcol[i];
            if(row>=0 && row<m && col>=0 && col<n && vis[row][col]==0 && board[row][col]=='O'){
                dfx({row,col},board,vis);
            }
        }
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfx({i,0},board,vis);
            }
            if(board[i][n-1]=='O' && vis[i][n-1]==0){
                dfx({i,n-1},board,vis);
            }
        }
         for(int j=0;j<n;j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfx({0,j},board,vis);
            }
             if(board[m-1][j]=='O' && vis[m-1][j]==0){
                dfx({m-1,j},board,vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};