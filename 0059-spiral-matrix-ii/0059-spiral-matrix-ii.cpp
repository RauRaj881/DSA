class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> mat(n,vector<int>(n));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int cr=1;
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++){
                mat[top][i]=cr;
                cr++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                mat[i][right]=cr;
                cr++;
            }
            right--;
            if(top>bottom){break;}
            for(int i=right;i>=left;i--){
                mat[bottom][i]=cr;
                cr++;
            }
            bottom--;
            if(left>right){break;}
            for(int i=bottom;i>=top;i--){
                mat[i][left]=cr;
                cr++;
            }
            left++;
        }
        return mat;
    }
};