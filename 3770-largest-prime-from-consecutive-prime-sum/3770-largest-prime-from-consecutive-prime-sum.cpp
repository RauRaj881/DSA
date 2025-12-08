class Solution {
public:
    int largestPrime(int n) {
        if(n==1){return 0;}
        vector<int> sieve(n+1,-1);
        for(long long i=2;i<=n;i++){
            for(long long j=i*i;j<=n;j+=i){
                sieve[j]=1;
            }
        }
        int sum=0,idx=1,ans=0;;
        for(int i=2;i<=n;i++){
            if(sieve[i]==-1){
                sum+=i;
                if(sum>n){break;}
                else if(sieve[sum]==-1){ans=sum;}
            }
            }
        return ans;
    }
};