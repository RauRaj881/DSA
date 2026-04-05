typedef long long ll;
class Solution {
public:
    long long minIncrease(vector<int>& nums){
        int n=nums.size();
        if(n%2==1){
            ll ans=0;
            for(int i=1;i<n-1;i+=2){
                int f=max(nums[i-1],nums[i+1]);
                ans+=max(0,f-nums[i]+1);
            }
            return ans;
        }
        ll cr=0,cr2=0;
        vector<ll> pre(n,0),suf(n,0);
        for(int i=1;i<n-1;i+=2){
            int f=max(nums[i-1],nums[i+1]);
            cr+=max(0,f-nums[i]+1);
            pre[i]=cr;   
        }
        for(int i=2;i<n-1;i+=2){
            int f=max(nums[i-1],nums[i+1]);
            cr2+=max(0,f-nums[i]+1);   
        }
        ll ans2=min(cr,cr2);
        for(int i=n-2;i>=1;i-=2){
            int f=max(nums[i-1],nums[i+1]);
            int vl=max(0,f-nums[i]+1);
            suf[i]=(i<=n-3?suf[i+2]:0)+vl;
        }
        ll cr3=0;
        for(int i=3;i<n-1;i+=2){
            ans2=min(ans2,pre[i-2]+suf[i+1]);
        }
        return ans2;
    }
};