class Solution {
public:
void bld(vector<vector<int>>& ft, vector<vector<int>>& sd){
    int n=ft.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sd[i][j]=ft[n-j-1][i];
        }
    }
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int n=mat.size();
        vector<vector<int>> mat2(n,vector<int>(n));
        vector<vector<int>> mat3(n,vector<int>(n));
        vector<vector<int>> mat4(n,vector<int>(n));
        bld(mat,mat2);
        bld(mat2,mat3);
        bld(mat3,mat4);
        return (tar==mat||tar==mat2||tar==mat3||tar==mat4);
    }
};