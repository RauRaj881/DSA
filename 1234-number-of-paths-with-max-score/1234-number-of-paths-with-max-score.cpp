class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9));
        vector<vector<int>> ways(n,vector<int>(n,0));
        dp[0][0]=0;
        ways[0][0]=1;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){continue;}
                if(board[i][j]=='X'){dp[i][j]=-1e9;}
                else{
                    int left=-1e9,up=-1e9,leftup=-1e9;
                    if(j>0){left=dp[i][j-1];}
                    if(i>0){up=dp[i-1][j];}
                    if(i>0&&j>0){leftup=dp[i-1][j-1];}
                    int best=max(left,max(up,leftup));
                    int val=(board[i][j]=='S'?0:(board[i][j]-'0'));
                    if(best!=-1e9){dp[i][j]=best+val;}
                    if(i>0&&best==up&&best!=-1e9){ways[i][j]=(ways[i][j]+ways[i-1][j])%mod;}
                    if(j>0&&best==left&&best!=-1e9){ways[i][j]=(ways[i][j]+ways[i][j-1])%mod;}
                    if(i>0&&best==leftup&&best!=-1e9){ways[i][j]=(ways[i][j]+ways[i-1][j-1])%mod;}
                }
            }
        }
        if(dp[n-1][n-1]==-1e9){return {0,0};}
        return {dp[n-1][n-1],ways[n-1][n-1]};
    }
};