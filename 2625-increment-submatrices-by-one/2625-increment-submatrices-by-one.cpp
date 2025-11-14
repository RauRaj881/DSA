/* // O(n^2*m)
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
};*/
// using difference array technique O(n^2+m);
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            vector<int> curr=queries[i];
            int r1=curr[0],c1=curr[1];
            int r2=curr[2],c2=curr[3];
            ans[r1][c1]++;
            if(r2+1<n){ans[r2+1][c1]--;}
            if(c2+1<n){ans[r1][c2+1]--;}
            if(r2+1<n&&c2+1<n){ans[r2+1][c2+1]++;}
        }
        for(int r=0;r<n;r++){
            for(int c=1;c<n;c++){
                ans[r][c]+=ans[r][c-1];
            }
        }
        for(int c=0;c<n;c++){
            for(int r=1;r<n;r++){
                ans[r][c]+=ans[r-1][c];
            }
        }
        return ans;
    }
};