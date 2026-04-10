typedef long long ll;
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k){
        int n=nums.size();
        vector<ll> pre(n);
        pre[0]=nums[0]%k;
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]+nums[i])%(k);
        }
        long long ans=0;
        unordered_map<ll,ll> mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            ans+=(mp[pre[i]]);
            mp[pre[i]]++;
        }
        ll i=0;
        while(i<n){
            ll j=i;
            while(j<n){
                if(nums[i]==nums[j]){j++;}
                else{break;}
            }
            ll x=k/__gcd(k,nums[i]);
            for(ll l=x;l<=j-i;l+=x){ans-=(j-i-l);}
            i=j;
        }
        return ans;
    }
};