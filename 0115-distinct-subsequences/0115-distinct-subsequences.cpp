class Solution {
public:
int dissub(int index1,int index2,vector<vector<int>> &dp,string &s, string &t){
    if(index2<0){return 1;}
    if(index1<0){return 0;}
    if(dp[index1][index2]!=-1){return dp[index1][index2];}
    if(s[index1]==t[index2]){
        return dp[index1][index2]=dissub(index1-1,index2-1,dp,s,t)+dissub(index1-1,index2,dp,s,t);
    }
    else{
        return dp[index1][index2]=dissub(index1-1,index2,dp,s,t);
    }
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dissub(n-1,m-1,dp,s,t);
    }
};