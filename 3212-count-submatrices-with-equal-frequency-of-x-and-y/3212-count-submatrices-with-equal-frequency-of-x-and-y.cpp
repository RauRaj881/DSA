class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> colx(m,0);
        vector<int> coly(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int cnty=0,cntx=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){colx[j]++;}
                if(grid[i][j]=='Y'){coly[j]++;}
                cnty+=coly[j];
                cntx+=colx[j];
                if(cntx>0&&cnty==cntx){ans++;}
            }
        }
        return ans;
    }
};