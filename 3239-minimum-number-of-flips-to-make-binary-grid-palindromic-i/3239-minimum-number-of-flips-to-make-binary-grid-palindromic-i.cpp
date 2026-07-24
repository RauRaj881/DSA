class Solution {
public:
    int minFlips(vector<vector<int>>& grid){
        int ans1=0,ans2=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                if(grid[i][j]!=grid[i][m-1-j]){ans1++;}
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                if(grid[j][i]!=grid[n-1-j][i]){ans2++;}
            }
        }
        return min(ans1,ans2);
    }
};