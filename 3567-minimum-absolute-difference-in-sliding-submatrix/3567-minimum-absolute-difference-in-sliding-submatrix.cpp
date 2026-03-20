class Solution {
public:
int f(int i,int j,vector<vector<int>>& grid,int k){
    int n=grid.size();
    int m=grid[0].size();
    int mn=1e8;
    vector<int> temp;
    for(int r=i;r<(i+k);r++){
        for(int c=j;c<(j+k);c++){
            temp.push_back(grid[r][c]);
        }
    }
    sort(temp.begin(),temp.end());
    for(int idx=1;idx<temp.size();idx++){
        if(temp[idx]!=temp[idx-1])mn=min(mn,temp[idx]-temp[idx-1]);
    }
    if(mn==1e8){mn=0;}
    return mn;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<=(n-k);i++){
            vector<int> cr;
            for(int j=0;j<=(m-k);j++){
                int x=f(i,j,grid,k);
                cr.push_back(x);
            }
            ans.push_back(cr);
        }
        return ans;
    }
};