class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k){
        int n=grid.size();
        int m=grid[0].size();
        int d=x+x+k-1;
        for(int i=x;i<x+k/2;i++){
            for(int j=y;j<y+k;j++){
                int a=grid[i][j];
                int b=grid[d-i][j];
                grid[i][j]=b;
                grid[d-i][j]=a;
            }
        }
        return grid;
    }
};