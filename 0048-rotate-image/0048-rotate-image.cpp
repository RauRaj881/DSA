class Solution {
public:
    void rotate(vector<vector<int>>& mat1){
        vector<vector<int>> mat2=mat1;
        int n=mat2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            mat1[j][n-i-1]=mat2[i][j];
            }
        }
    }
};