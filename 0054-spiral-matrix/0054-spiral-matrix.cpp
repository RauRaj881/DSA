class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom&&left<=right){
            int i=top,j=left;
            while(j<=right){
                ans.push_back(matrix[top][j]);
                j++;
            }
            top++;
            i=top;
            while(i<=bottom){
                ans.push_back(matrix[i][right]);
                i++;
            }
            right--;
            j=right;
            if(top>bottom){break;}
            while(j>=left){
                ans.push_back(matrix[bottom][j]);
                j--;
            }
            bottom--;
            i=bottom;
            if(left>right){break;}
            while(i>=top){
                ans.push_back(matrix[i][left]);
                i--;
            }
            left++;
        }
        return ans;
    }
};