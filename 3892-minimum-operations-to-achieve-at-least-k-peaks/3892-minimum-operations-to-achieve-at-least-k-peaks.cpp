typedef long long ll;
class Solution {
public:
ll fn(int st,int ed,vector<int>& nums, int k){
    if(k==0){return 0;}
    //if(ed<st){return 1e9;}
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX));
    for(int i=st;i<=ed;i++){dp[i][0]=0;}
    int pi=(st-1+n)%n,ni=(st+1+n)%n;
    int f1=max(nums[ni],nums[pi]);
    int ic=max(0,f1-nums[st]+1);
    int pi2=(st+n)%n,ni2=(st+2+n)%n;
    int f2=max(nums[ni2],nums[pi2]);
    int ic2=max(0,f2-nums[st+1]+1);
    dp[st][1]=ic;
    dp[st+1][1]=min(dp[st][1],ic2);
    for(int i=st+2;i<=ed;i++){
        for(int j=1;j<=k;j++){
            int nt=INT_MAX;
            if(i>st){nt=dp[i-1][j];}
            int t=INT_MAX;
            t=dp[i-2][j-1];
            int pi=(i-1+n)%n;
            int ni=(i+1+n)%n;
            if(t!=INT_MAX){
                int f=max(nums[ni],nums[pi]);
                int ic=max(0,f-nums[i]+1);
                t+=ic; 
            }
            dp[i][j]=min(nt,t);
        }
    }
    return dp[ed][k];
}
    int minOperations(vector<int>& nums, int k){
        int n=nums.size();
        if(k==0){return 0;}
        if(k>n/2){return -1;}
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;
        ll a=fn(1,n-1,nums,k);
        ll b=fn(2,n-2,nums,k-1);
        int f=max(nums[n-1],nums[1]);
        int ic=max(0,f-nums[0]+1);
        b+=ic;
        return min(a,b);
    }
};