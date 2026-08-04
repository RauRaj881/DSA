class Solution {
public:
    string stoneGameIII(vector<int>& s){
        int n=s.size();
        vector<int> dp(n+1,INT_MIN);
        dp[n]=0;
        //for(int i=0;i<n;i++){
          //  dp[i]=s[i];
        //}
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2&&i+j<n;j++){
                int k=i+j,cr=0;
                for(int tp=i;tp<=k;tp++){cr+=s[tp];}
                dp[i]=max(dp[i],cr-dp[i+j+1]);
            }
        }
        if(dp[0]>0){return "Alice";}
        else if(dp[0]<0){return "Bob";}
        return "Tie";
    }
};