class Solution {
public:
long long mod=1e9+7;
long long power(long long x,long long n){
    if(n==0){return 1;}
    long long res=1;
    while(n!=1){
        if(n%2==0){
            x=(x*x)%mod;
            n/=2;
        }
        else{
            res=(res*x)%mod;
            n--;
        }
    }
    res=(res*x)%mod;
    return res;
}
    int countGoodNumbers(long long n){
        long long cnte=(n+1)/2;
        long long cnto=n/2;
        long long tot1=power(5,cnte);
        long long tot2=power(4,cnto);
        return (tot1*tot2)%mod;
    }
};