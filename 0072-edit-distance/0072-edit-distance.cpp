class Solution {
public:
    int minDistance(string w1,string w2){
        int n1=w1.size();
        int n2=w2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,1e9));
        //dp[i][j]=min no of operations to convert w1[0,1....i-1] to w2[0,1...j-1]
        for(int j=0;j<=n2;j++){dp[0][j]=j;}
        for(int i=0;i<=n1;i++){dp[i][0]=i;}
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    int ins=1+dp[i][j-1];
                    dp[i][j]=min({del,ins,rep});
                }
            }
        }
        return dp[n1][n2];
    }
};