class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        int col=s.size();
        int row=numRows;
        vector<vector<char>> v(row,vector<char>(col,'*'));
        int k=0,i=0,j=0;
        while(k<n&&i<row&&j<col){
            while(i<row&&k<col){
                v[i][j]=s[k];
                i++;
                k++;
            }
            if(i==row){
                i-=2;j++;
                while(i>=1&&k<n){
                    v[i][j]=s[k];
                    i--;j++;k++;
                }
            }
            if(i<0){i=0;}
        }
        string ans="";
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(v[i][j]!='*'){
                    ans+=v[i][j];
                }
            }
        }
        return ans;
    }
};