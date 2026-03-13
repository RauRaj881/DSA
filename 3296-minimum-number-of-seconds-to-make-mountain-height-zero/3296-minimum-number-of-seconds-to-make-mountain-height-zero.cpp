typedef long long ll;
class Solution {
public:
bool ispossible(ll mid,ll mH,vector<int>&wT){
    ll mx=0;
    for(int i=0;i<wT.size();i++){
        ll num=(ll)wT[i];
        ll cr=0;
        ll cnt=1;
        while(cr<=mid){
            if(cr+num*cnt>mid){break;}
            else{cr+=num*cnt;mH--;cnt++;}
            if(mH<=0){break;}
        }
        if(mH<=0){break;}
    }
    if(mH<=0){return true;}
    return false;
}
    long long minNumberOfSeconds(int mH,vector<int>& wT){
        ll ans=-1;
        ll low=0,high=1e18;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(ispossible(mid,(ll)mH,wT)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};