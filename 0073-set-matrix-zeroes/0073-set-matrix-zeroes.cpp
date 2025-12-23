class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    for(int row=0;row<m;row++){
                        if(mat[row][j]!=0)mat[row][j]=1067893;
                    }
                    for(int col=0;col<n;col++){
                        if(mat[i][col]!=0)
                        mat[i][col]=1067893;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1067893){mat[i][j]=0;}
            }
        }
    }
};