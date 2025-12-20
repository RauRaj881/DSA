class Solution {
public:
    long long lastInteger(long long n) {
        long long len=n,a=1,d=1,step=0;;
        while(len!=1){
            if(step%2==1&&len%2==0){
                a=a+d;
            }
            d*=2;
            step++;
            len=(n-a)/d+1;
        }
        return a;   
    }
};