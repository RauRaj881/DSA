class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k){
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        for(int i=0;i<n;i++){
            int idx=k;
            if(i%2==1){idx=m-k;}
            idx%=m;
            for(int j=0;j<m;j++){
                if(mat[i][j]!=mat[i][idx]){return false;}
                idx=(idx+1)%m;
            }
        }
        return true;
    }
};