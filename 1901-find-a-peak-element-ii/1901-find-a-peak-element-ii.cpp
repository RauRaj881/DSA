class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int midcol=(low+high)/2;
            int maxrow=0;
            for(int i=0;i<n;i++){
                if(mat[i][midcol]>mat[maxrow][midcol]){
                    maxrow=i;
                }
            }
            int left=(midcol>0?mat[maxrow][midcol-1]:-1);
            int right=(midcol<m-1?mat[maxrow][midcol+1]:-1);
            if(mat[maxrow][midcol]>left&&mat[maxrow][midcol]>right){return {maxrow,midcol};}
            else if(mat[maxrow][midcol]<left){high=midcol-1;}
            else{low=midcol+1;}
        }
        return {-1,-1};
        
    }
};