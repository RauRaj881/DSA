class Solution {
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
};