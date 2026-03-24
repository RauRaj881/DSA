class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        long pref=1,suf=1;
        long mod=12345;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=pref;
                pref=(pref*grid[i][j])%(mod);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*suf)%(mod);
                suf=(suf*grid[i][j])%(mod);
            }
        }
        return ans;
    }
};