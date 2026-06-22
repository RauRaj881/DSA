class Solution {
public:
long long f(long long mid,int x){
    long long tot=0;
    for(int i=x-1;i<63;i+=x){
        long long len=(1LL<<(i+1));
        long long cycle=(mid+1)/len;
        long long rem=(mid+1)%len;
        tot+=(cycle)*(1LL<<(i));
        long long tp=rem-(1LL<<(i));
        if(tp>0){tot+=tp;}
    }
    return tot;
}
    long long findMaximumNumber(long long k, int x){
        long long low=1,high=1e15;
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if(f(mid,x)<=k){ans=mid;low=mid+1;}
            else{high=mid-1;}
        }
        return ans;
        
    }
};