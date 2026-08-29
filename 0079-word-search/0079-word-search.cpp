class Solution {
public:
bool pos=false;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void f(int row,int col,vector<vector<char>>& b,string w,int i){
    int n=b.size(),m=b[0].size();
    if(b[row][col]!=w[i]){return;}
    if(i==w.size()-1){pos=true;return;}
    char ch=b[row][col];
    b[row][col]='#';
    for(int k=0;k<4;k++){
        int nr=row+dx[k];
        int nc=col+dy[k];
        if(nr<0||nr>=n||nc<0||nc>=m||b[nr][nc]=='#'){continue;}
        f(nr,nc,b,w,i+1);
    }
    b[row][col]=ch;
}
    bool exist(vector<vector<char>>& b,string w){
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f(i,j,b,w,0);
            }
        }
        return pos;
    }
};