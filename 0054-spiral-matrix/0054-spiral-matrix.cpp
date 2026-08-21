class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int left=0,right=m-1;
        int top=0,bottom=n-1;
        while(left<=right&&top<=bottom){
            int i=left;
            while(i<=right){
                ans.push_back(mat[top][i]);i++;
            }
            top++;
            i=top;
            if(top>bottom){break;}
            while(i<=bottom){
                ans.push_back(mat[i][right]);i++;
            }
            right--;
            i=right;
            if(left>right){break;}
            while(i>=left){
                ans.push_back(mat[bottom][i]);i--;
            }
            bottom--;
            i=bottom;
            if(top>bottom){break;}
            while(i>=top){
                ans.push_back(mat[i][left]);i--;
            }
            left++;
        }
        return ans;
    }
};