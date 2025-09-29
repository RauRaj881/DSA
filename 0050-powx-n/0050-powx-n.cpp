class Solution {
public:
    int ans=1;
    double myPow(double x, int n) {
        int m=n;
        n=abs(n);
        double ans=1;
        while(n!=0){
            if(n%2==0){
                x*=x;
                n/=2;
            }
            else{
                ans*=x;
                n-=1;
            }

        }
        if(m<0){return 1/ans;}
        return ans;
    }
};