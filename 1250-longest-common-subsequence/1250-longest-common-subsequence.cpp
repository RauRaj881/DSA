class Solution {
public:
int locs(int index1,int index2,string &text1,string &text2,vector<vector<int>> &dp){
    if (index1 < 0 || index2 < 0) return 0;
    int take=0;
    if(dp[index1][index2]!=-1){return dp[index1][index2];}
    if(text1[index1]==text2[index2]){
        take=1+locs(index1-1,index2-1,text1,text2,dp);
    }
    int nottake=max(locs(index1-1,index2,text1,text2,dp),locs(index1,index2-1,text1,text2,dp));
    return dp[index1][index2]=max(take,nottake);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return locs(n1-1,n2-1,text1,text2,dp);      
    }
};