//memoization
/*class Solution {
public:
int mind(int index1,int index2,vector<vector<int>> &dp,string &word1, string &word2){
    if(index1<0){return index2+1;}
    if(index2<0){return index1+1;}
    if(dp[index1][index2]!=-1){return dp[index1][index2];}
    if(word1[index1]==word2[index2]){
        return dp[index1][index2]=mind(index1-1,index2-1,dp,word1,word2);
    }
    else{
        int del=1+mind(index1-1,index2,dp,word1,word2);
        int insert=1+mind(index1,index2-1,dp,word1,word2);
        int replace=1+mind(index1-1,index2-1,dp,word1,word2);
        return dp[index1][index2]=min(del,min(insert,replace));
    }
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return mind(n-1,m-1,dp,word1,word2); 
    }
};*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
        dp[i][j]=dp[i-1][j-1];
            }
       else{
        int del=1+dp[i-1][j];
        int insert=1+dp[i][j-1];
        int replace=1+dp[i-1][j-1];
        dp[i][j]=min(del,min(insert,replace));
              }
            }
        }
        return dp[n][m];
    }
};