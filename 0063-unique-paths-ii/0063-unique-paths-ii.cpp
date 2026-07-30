class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1){return 0;}
        vector<int> prv(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){cur[0]=1;continue;}
                if(grid[i][j]==1){continue;}
                int lt=0,up=0;
                if(i>0){up=prv[j];}
                if(j>0){lt=cur[j-1];}
                cur[j]=lt+up;
            }
            prv=cur;
        }
        return prv[n-1];
    }
};