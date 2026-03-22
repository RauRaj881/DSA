class Solution { 
public: 
    int minRemovals(vector<int>& nums, int target) { 
        int n=nums.size(); 
        long long sz=1<<14; 
        vector<unordered_map<int,long long>> dp(n); 
        dp[0][nums[0]]=1; 
        if(nums[0]!=0)dp[0][0]=0; 
        for(int i=1;i<n;i++){ 
            for(int j=0;j<=1e4;j++){ 
                int xr=j^nums[i]; 
                if(dp[i-1].count(j)){dp[i][j]=dp[i-1][j];} 
                if(dp[i-1].count(xr)){dp[i][j]=max(dp[i-1][xr]+1,dp[i][j]);}
            } 
        }
        if(!dp[n-1].count(target)){return -1;} 
        return n-dp[n-1][target]; 
    } 
};