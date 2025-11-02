class Solution {
public:
void fill(int i,int j,vector<vector<int>> &grid,int m,int n){
    for(int r=i+1;r<m;r++){
        if(grid[r][j]==1){break;}
        else{grid[r][j]=2;}
    }
    for(int r=i-1;r>=0;r--){
        if(grid[r][j]==1){break;}
        else{grid[r][j]=2;}
    }
    for(int c=j+1;c<n;c++){
        if(grid[i][c]==1){break;}
        else{grid[i][c]=2;}
    }
    for(int c=j-1;c>=0;c--){
        if(grid[i][c]==1){break;}
        else{grid[i][c]=2;}
    }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]=1;
        }
        for(int i=0;i<guards.size();i++){
            fill(guards[i][0],guards[i][1],grid,m,n);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){cnt++;}
            }
        }
        return cnt;
    }
};