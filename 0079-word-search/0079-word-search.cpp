class Solution {
public:
bool pos=false;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void f(int row,int col,vector<vector<char>>& b,string w,int i,vector<vector<int>>& vis){
    int n=b.size(),m=b[0].size();
    if(b[row][col]!=w[i]){return;}
    if(i==w.size()-1){pos=true;return;}
    vis[row][col]=1;
    for(int k=0;k<4;k++){
        int nr=row+dx[k];
        int nc=col+dy[k];
        if(nr<0||nr>=n||nc<0||nc>=m||vis[nr][nc]==1){continue;}
        f(nr,nc,b,w,i+1,vis);
    }
    vis[row][col]=-1;
}
    bool exist(vector<vector<char>>& b,string w){
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n,vector<int>(m,-1));
                f(i,j,b,w,0,vis);
            }
        }
        return pos;
    }
};