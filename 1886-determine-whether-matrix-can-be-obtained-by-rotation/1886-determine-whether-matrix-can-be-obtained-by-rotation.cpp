class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar){
        bool a=true,b=true,c=true,d=true;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=tar[i][j]){a=false;}
                if(mat[n-j-1][i]!=tar[i][j]){b=false;}
                if(mat[n-i-1][n-j-1]!=tar[i][j]){c=false;}
                if(mat[j][n-i-1]!=tar[i][j]){d=false;}
            }
        }
        return a||b||c||d;
    }
};