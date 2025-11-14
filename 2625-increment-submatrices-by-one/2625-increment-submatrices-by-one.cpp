class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            vector<int> curr=queries[i];
            for(int r=min(curr[0],curr[2]);r<=max(curr[0],curr[2]);r++){
                for(int c=min(curr[1],curr[3]);c<=max(curr[1],curr[3]);c++){
                    ans[r][c]++;
                }
            }
        }
        return ans;
    }
};