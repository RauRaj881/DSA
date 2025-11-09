//tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n2;j++){
            dp[0][j]=0;
        }
        int maxno=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int nottake=max(dp[i-1][j],dp[i][j-1]);
                int take=0;
                if(word1[i-1]==word2[j-1]){
                    take=1+dp[i-1][j-1];
                }
                dp[i][j]=max(take,nottake);
                maxno=max(maxno,dp[i][j]);
            }
        }
        return n1+n2-2*dp[n1][n2];
    }
};
//space optimization
/*class Solution {
public:
    int minDistance(string word1, string word2) {
         int n1=word1.size();
        int n2=word2.size();
        vector<int> prev(n2+1,0);
        int maxno=0;
        for(int i=1;i<=n1;i++){
            vector<int> curr(n2+1);
            for(int j=1;j<=n2;j++){
                int nottake=max(prev[j],curr[j-1]);
                int take=0;
                if(word1[i-1]==word2[j-1]){
                    take=1+prev[j-1];
                }
                curr[j]=max(take,nottake);
                maxno=max(maxno,curr[j]);
            }
            prev=curr;
        }
        return (n1+n2)-2*maxno;
    }
};*/