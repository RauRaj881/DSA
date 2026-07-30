class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prv(n,-1);
        for(int i=0;i<m;i++){
            vector<int> cur(n,-1);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){cur[0]=grid[0][0];continue;}
                int lt=INT_MAX,up=INT_MAX;
                if(i>0){up=prv[j];}
                if(j>0){lt=cur[j-1];}
                cur[j]=grid[i][j]+min(up,lt);
            }
            prv=cur;
        }
        return prv[n-1];
        
    }
};