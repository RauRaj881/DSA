class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long sign=1;
        if((dividend>=0&&divisor<0)||(dividend<0&&divisor>0)){sign=-1;}
        if(dividend==divisor){return 1;}
        long long divid=abs((long long)dividend);
        long long divis=abs((long long)divisor);
        long long x;
        long long ans=0;
        long long rem=divid;
        while(rem>=divis){
            x=0;
        while(rem>=(divis<<(x+1))){
            x++;
            }
            ans+=1LL<<x;
            rem-=(divis*(1LL<<(x)));
        }
        if(sign==-1){ans*=-1;}
        if(ans>INT_MAX){return INT_MAX;}
        else  if(ans<INT_MIN){return INT_MIN;}
        return (int)ans;
    }
};