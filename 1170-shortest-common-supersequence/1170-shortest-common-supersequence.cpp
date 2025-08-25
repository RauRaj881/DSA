class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=n2;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int nottake=max(dp[i-1][j],dp[i][j-1]);
                int take=0;
                if(str1[i-1]==str2[j-1]){
                    take=1+dp[i-1][j-1];
                }
                dp[i][j]=max(take,nottake);
            }
        }
        int i=n1,j=n2;
        string s="";
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(str1[i-1]);
                    i--;
                }
                else{
                    s.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};