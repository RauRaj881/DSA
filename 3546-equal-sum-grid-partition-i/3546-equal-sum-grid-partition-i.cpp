class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot+=grid[i][j];
            }
        }
        if(tot%2!=0){return false;}
        long long sm1=0,sm2=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sm1+=grid[i][j];
            }
            if(sm1==tot/2){return true;}
        }
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                sm2+=grid[i][j];
            }
            if(sm2==tot/2){return true;}
        }
        return false;
    }
};