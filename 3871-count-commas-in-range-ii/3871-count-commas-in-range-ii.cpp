class Solution {
public:
    long long countCommas(long long n) {
        long long cnt=0;
        long long ori=n;
        while(n!=0){
            cnt++;
            n/=10;
        }
        int x=(cnt-1)/3;
        long long tp=cnt-1;
        long long p = 1;
        while(tp>0) {p *= 10;tp--;}
        long long ans=(ori-p+1)*(x);
        cnt--;

        long long p2=1;
        long long tp2=cnt-1;
        while(tp2>0) {p2 *= 10;tp2--;};
        p2*=9;
        while(cnt>3){
            long long x2=(cnt-1)/3;
            ans+=(x2)*(p2);
            p2/=10;
            cnt--;
        }
        return ans;
    }
};