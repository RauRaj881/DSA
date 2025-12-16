class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> res(n,vector<int>(n,1e9));
        set<pair<int, pair<int, int>>> s;
        s.insert({1,{0,0}});
        if(grid[0][0]==1 ||grid[n-1][n-1]==1){return -1;}
        int drow[3]={-1,0,1};
        int dcol[3]={-1,0,1};
        res[0][0]=1;
        while(!s.empty()){
            auto temp =*(s.begin());
            int row=temp.second.first;
            int col=temp.second.second;
            s.erase(temp);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[j];
                    if(!(i==1 && j==1) && nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                        if(grid[nrow][ncol]==0 && res[nrow][ncol]>res[row][col]+1){
                            /*if(res[nrow][ncol]!=1e9)*/s.erase({res[nrow][ncol],{nrow,ncol}});
                            s.insert({res[row][col]+1,{nrow,ncol}});
                            res[nrow][ncol]=res[row][col]+1;
                        }
                    }
                }
            }
        }
        if(res[n-1][n-1]!=1e9){
            return res[n-1][n-1];
        }
        return -1;
    }
};