class Solution {
public:
    int countPrimes(int n){
        vector<int> v(n+1,-1);
        for(long long i=2;i<=n;i++){
            for(long long j=i*i;j<=n;j+=i){
                v[j]=1;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(v[i]==-1){cnt++;}
        }
        return cnt;
    }
};