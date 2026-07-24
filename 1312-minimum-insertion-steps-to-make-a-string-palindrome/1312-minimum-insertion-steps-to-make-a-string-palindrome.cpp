//tabulation
class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        if(s[0]==t[0]){dp[0][0]=1;}
    for(int j=1;j<n;j++){if(s[0]==t[j]){dp[0][j]=1;}else{dp[0][j]=dp[0][j-1];}}
    for(int j=1;j<n;j++){if(s[j]==t[0]){dp[j][0]=1;}else{dp[j][0]=dp[j-1][0];}}
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(s[i]==t[j]){dp[i][j]=1+dp[i-1][j-1];}
                else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
            }
        }
        return n-dp[n-1][n-1];
    }
};
/*class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        int maxno=0;
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                int nottake=max(prev[j],curr[j-1]);
                int take=0;
                if(s[i-1]==t[j-1]){
                    take=1+prev[j-1];
                }
                curr[j]=max(take,nottake);
                maxno=max(maxno,curr[j]);
            }
            prev=curr;
        }
        return n-maxno;
    }
};*/