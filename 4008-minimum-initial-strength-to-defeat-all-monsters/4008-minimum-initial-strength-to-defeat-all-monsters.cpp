#define ll long long
class Solution {
public:
bool f(ll mid,vector<int>& m,vector<ll>& df){
    int i;
    for(i=0;i<m.size();i++){
        if(mid+df[i]>=m[i]){mid-=m[i];mid=max(0LL,mid);}
        else{break;}
    }
    return i>=m.size();
}
    long long minInitialStrength(vector<int>& m,vector<vector<int>>& b){
        int n=m.size();
        ll sm=0;
        for(auto it:m){sm+=it;}
        ll low=0;
        ll high=sm,ans=sm;
        vector<ll> df(n+1,0);
        for(int i=0;i<b.size();i++){
            int l=b[i][0],r=b[i][1],v=b[i][2];
            df[l]+=v;
            df[r+1]-=v;
        }
        for(int i=1;i<n;i++){
            df[i]+=df[i-1];
        }
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(f(mid,m,df)){ans=mid;high=mid-1;}
            else{low=mid+1;}
        }
        return ans;
    }
};