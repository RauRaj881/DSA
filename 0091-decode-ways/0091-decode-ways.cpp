class Solution {
public:
int f(int i,int n,string& s,vector<int>&dp){
    if(i==n){return 1;}
    if(dp[i]!=-1){return dp[i];}
    char current=s[i];
    int ways=0;
    if(current-'0'!=0){
        ways+=f(i+1,n,s,dp);
    }
    int a=s[i]-'0';
    if(i<n-1){
        int b=s[i+1]-'0';
        char tt=a*10+b+'0';
        if(a!=0&&(tt-'0'>=10&&tt-'0'<=26)){
            ways+=f(i+2,n,s,dp);
        }
    }
    return dp[i]=ways;
}
    int numDecodings(string s){
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp);
    }
};