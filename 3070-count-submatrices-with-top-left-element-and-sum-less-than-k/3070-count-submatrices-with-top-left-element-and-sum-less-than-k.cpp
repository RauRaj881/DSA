class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<int> colsm(m,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                colsm[j]+=grid[i][j];
                cnt+=colsm[j];
                if(cnt<=k){ans++;}
            }
        }
        return ans;
    }
};