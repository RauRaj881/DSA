class Solution {
public:
bool isprime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){return false;}
    }
    return true;
}
    int countPrimeSetBits(int l, int r){
        int ans=0;
        for(int i=l;i<=r;i++){
            int x=__builtin_popcount(i);
            if(x>1&&isprime(x)){ans++;}
        }
        return ans;
    }
};