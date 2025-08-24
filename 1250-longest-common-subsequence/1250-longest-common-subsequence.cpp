//memoization
/*class Solution {
public:
int locs(int index1,int index2,string &text1,string &text2,vector<vector<int>> &dp){
    if (index1 == 0 || index2 == 0) return 0;
    int take=0;
    if(dp[index1][index2]!=-1){return dp[index1][index2];}
    if(text1[index1-1]==text2[index2-1]){
        take=1+locs(index1-1,index2-1,text1,text2,dp);
    }
    int nottake=max(locs(index1-1,index2,text1,text2,dp),locs(index1,index2-1,text1,text2,dp));
    return dp[index1][index2]=max(take,nottake);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return locs(n1,n2,text1,text2,dp);      
    }
};*/
//tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
         for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int take=0;
                if(text1[i-1]==text2[j-1]){
                    take=1+dp[i-1][j-1];
                    }
                int nottake=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n1][n2];
    }
};