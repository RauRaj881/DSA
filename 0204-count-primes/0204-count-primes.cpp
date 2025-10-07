class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n,1);
        int cnt=0;
        for(long long i=2;i<n;i++){
            if(prime[i]==1){
                cnt++;
                for(long long j=i;j<n;j+=i){
                prime[j]=0;
            }
            }
        }
        return cnt;
    }
};
//TC=O(nlog(logn)) just remember it.(Sieve of Eratosthenes)
//SC=O(n)