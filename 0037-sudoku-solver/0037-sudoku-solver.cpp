class Solution {
public:
bool isvalid(int row,int col,int k,vector<vector<char>>& b){
    for(int i=0;i<9;i++){
        if(b[i][col]==char(k+'0')){
            return false;
        }
        if(b[row][i]==char(k+'0')){
            return false;
        }
        if(b[3*(row/3)+i/3][3*(col/3)+i%3]==char(k+'0')){
            return false;
        }
    }
    return true;
}
bool finished=false;
    void solveSudoku(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){continue;}
                for(int k=1;k<=9;k++){
                    if(isvalid(i,j,k,b)){
                        b[i][j]=k+'0';
                        solveSudoku(b);
                        if(finished){return;}
                    }
                    b[i][j]='.';
                }
                return;
            }
        }
        finished=true;
        
    }
};