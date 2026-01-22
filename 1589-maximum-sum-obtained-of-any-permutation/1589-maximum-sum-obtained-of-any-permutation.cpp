class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n=nums.size();
        vector<int> a(n,0);
        int r=req.size();
        for(int i=0;i<r;i++){
            int l=req[i][0];
            int r=req[i][1];
            if(r<n-1){
                a[r+1]--;
            }
            a[l]++;
        }
        vector<int> g(n,0);
        g[0]=a[0];
        for(int i=1;i<n;i++){
            g[i]+=g[i-1]+a[i];
        }
        sort(g.begin(),g.end());
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=n-1,j=n-1;
        int mod=1e9+7;
        while(i>=0&&j>=0){
            ans=(ans+(long long)g[j]*nums[i])%mod;
        j--;i--;
        }
        return ans;
        
    }
};