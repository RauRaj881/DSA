class Solution {
public:
    string decodeCiphertext(string eT, int rows){
        int n=eT.size();
        if(n==0){return "";}
        int cols=(n)/rows;

        int x=0;
        vector<vector<char>> v(rows,vector<char>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                v[i][j]=eT[x];
                x++;
            }
        }
        string ans;
        for(int j=0;j<cols;j++){
            int i=0;
            int nj=j;
            while(i<rows&&nj<cols){
                ans+=v[i][nj];
                i++;nj++;
            }
        }
        int j=ans.size()-1;
        while(ans[j]==' '){j--;}
        return ans.substr(0,j+1);
    }
};