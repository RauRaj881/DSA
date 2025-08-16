//memoization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+prev[j];
                int leftd=matrix[i][j]+1e7;
                int rightd=matrix[i][j]+1e7;
                if(j>0){leftd=matrix[i][j]+prev[j-1];}
                if(j<n-1){rightd=matrix[i][j]+prev[j+1];}
                curr[j]=min(min(leftd,rightd),down);
            }
            prev=curr;
        }
        int minno=INT_MAX;
        for(int i=0;i<n;i++){
            minno=min(prev[i],minno);
        }
        return minno;
    }
};