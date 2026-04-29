class Solution {
public:
bool ispalin(int j,int i,string &s){
    while(j<i){
        if(s[j]!=s[i]){return false;}
        j++;i--;
    }
    return true;
}
    int minCut(string s){
        int n=s.size();
        vector<int> dp(n,n+1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(ispalin(j,i,s)){
                    int x=(j==0?0:dp[j-1]);
                    dp[i]=min(dp[i],x+1);
                }
            }
        }
        return dp[n-1]-1;
    }
};