typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums){
        int n=nums.size();
        vector<ll> v(1e5+5,0);
        v[0]=v[1]=1;
        for(ll i=2;i<1e5+5;i++){
            if(v[i]==0){
            for(ll j=i*i;j<=1e5+4;j+=i){
                v[j]=1;
            }
            }
        }
        ll lt=-1;
        vector<ll> p(1e5+5,-1);
        for(ll i=1e5+4;i>=0;i--){
            if(v[i]==0){lt=i;}
            p[i]=lt;
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll x=nums[i];
            if(i%2==1){
                if(v[x]==0){
                    if(x==2){ans+=2;}
                    else{ans+=1;}
                }
            }
            else{
                if(v[x]==1){
                    ans+=(ll)(p[x]-x);
                }
            }
        }
        return (int)ans;
    }
};