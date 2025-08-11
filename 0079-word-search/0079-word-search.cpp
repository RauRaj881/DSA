class Solution {
public:
bool doexist(int row,int col,vector<vector<char>>& board,string word,int index,int m,int n,vector<vector<int>> &vis,int drow[],int dcol[]){
    if(index==word.size()){
        return true;
    }
    if(row<0 ||row>=m ||col<0 ||col>=n ||word[index]!=board[row][col] ||vis[row][col]==1){
        return false;
    }
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){

                if(doexist(nrow,ncol,board,word,index+1,m,n,vis,drow,dcol)){
                    return true;
                }
            }
        }
        vis[row][col]=0;
        return false;
        }
    bool exist(vector<vector<char>>& board, string word) {
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1}; 
        int m=board.size();
        int n=board[0].size();
        if(m==1 && n==1 && word.size()==1 && board[0][0]==word[0]){return true;}
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(doexist(i,j,board,word,0,m,n,vis,drow,dcol)){
                    return true;
                }
            }
        }
        return false;     
    }
};