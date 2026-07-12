class Solution {
public:
    int minimumCost(vector<int>& nums, int k){
        int mod=1e9+7;
        int n=nums.size();
        long long ans=0;
        long long cnt=1;
        long long ork=k;
        for(int i=0;i<nums.size();i++){
            if(k>=nums[i]){k-=nums[i];}
            else{
                long long df=nums[i]-k;
                long long rq=(df+ork-1)/ork;
                k+=ork*rq;
                k-=nums[i];
                long long sm = ((rq%mod)*((cnt-1)%mod)) % mod;
                sm = (sm + ((rq * (rq + 1) / 2) % mod)) % mod;
                ans = (ans + sm) % mod;
                cnt+=rq;                   
            }
        }
        return ans%mod;
    }
};