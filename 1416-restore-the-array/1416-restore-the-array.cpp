class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        int mod=1e9+7;
        for(int i=n-1;i>=0;i--){
            long long num=s[i]-'0';
            if(num==0){continue;}
            int j=i;
            while(j<n&&num<=k){
                dp[i]=(dp[i]+dp[j+1])%(mod);
                j++;
                num=num*10+(long long)(s[j]-'0');
            }
        }
        return dp[0];
    }
};