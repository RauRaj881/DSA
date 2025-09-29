class Solution {
public:
    int ans=1;
    double myPow(double x, long long n) {
        double m=n;
        long long exp=abs(n);
        double ans=1;
        while(exp!=0){
            if(exp%2==0){
                x*=x;
                exp/=2;
            }
            else{
                ans*=x;
                exp-=1;
            }

        }
        if(m<0){return 1/ans;}
        return ans;
    }
};