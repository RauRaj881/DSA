class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    int cnt=0;
                    for(int c=0;c<n;c++){
                        if(mat[i][c]==1){cnt++;}
                    }
                    for(int r=0;r<m;r++){
                        if(mat[r][j]==1){cnt++;}
                    }
                    if(cnt==2){ans++;}
                }
            }
        }
        return ans;
    }
};