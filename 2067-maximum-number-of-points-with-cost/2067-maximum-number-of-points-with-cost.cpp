// TLE
/*class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n));
        for(int j=0;j<n;j++){
            dp[0][j]=points[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                long long mx=-1;
                for(int prevJ=0;prevJ<n;prevJ++){
                    long long curr=dp[i-1][prevJ]-abs(j-prevJ);
                    mx=max(mx,curr);
                    dp[i][j]=points[i][j]+mx;
                }
            }
        }
        long long ans=-1;
        for(int j=0;j<n;j++){
            ans=max(ans,dp[m-1][j]);
        }
        return ans;
    }
};*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<long long> curr(n);
        for(int j=0;j<n;j++){
            curr[j]=points[0][j];
        }
        for(int i=1;i<m;i++){
            vector<long long> left(n);
            vector<long long> right(n);
            left[0]=curr[0];
            for(int j=1;j<n;j++){
                left[j]=max(curr[j],left[j-1]-1);
            }
            right[n-1]=curr[n-1];
            for(int j=n-2;j>=0;j--){
                right[j]=max(curr[j],right[j+1]-1);
            }
            for(int j=0;j<n;j++){
            curr[j]=max(left[j],right[j])+points[i][j];
            }
        }
        long long ans=0;
        for(int j=0;j<n;j++){
            ans=max(ans,curr[j]);
        }
        return ans;
    }
};