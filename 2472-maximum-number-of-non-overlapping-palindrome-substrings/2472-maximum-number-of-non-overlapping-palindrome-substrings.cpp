class Solution {
public:
bool palin(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]){return false;}
        i++;j--;
    }
    return true;
}
    int maxPalindromes(string s, int k){
        int n=s.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+k-1;j<n;j++){
                if(palin(i,j,s)){
                    dp[j]=max(dp[j],(i>0?dp[i-1]:0)+1);
                }
                if(j>0)dp[j]=max(dp[j],dp[j-1]);
            }
        }
        return dp[n-1];        
    }
};