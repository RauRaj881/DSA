class Solution {
public:
bool ispalindrome(int i,int j,string & str){
    while(j>i){
        if(str[i]==str[j]){
            i++;j--;
        }
        else{return false;}
    }
    return true;
}
int f(int i,string &s,vector<int> &dp,int n){
    if(i==n||ispalindrome(i,n-1,s)){return 0;}
    if(dp[i]!=-1){return dp[i];}
    int mincuts=INT_MAX;
    for(int k=i;k<n;k++){
        int cuts=INT_MAX;
        if(ispalindrome(i,k,s)){
            cuts=1+f(k+1,s,dp,n);
        }
       mincuts=min(cuts,mincuts);
    }
    return dp[i]=mincuts;
}
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp,n);
    }
};