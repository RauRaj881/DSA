class Solution {
public:
int f(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
    if(i>j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int mincuts=INT_MAX;
    for(int k=i;k<=j;k++){
        int steps=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
        mincuts=min(steps,mincuts);
    }
    return dp[i][j]=mincuts;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(1,c,cuts,dp);
    }
};