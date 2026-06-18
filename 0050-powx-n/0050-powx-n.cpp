class Solution {
public:
    double myPow(double x, long long n){
        //if(INT_MIN){return 1;}
        if(n<0){n*=-1;x=1/x;}
        double ans=1;
        while(n!=0){
            if(n%2==0){n/=2;x*=x;}
            else{n-=1;ans*=x;}
        }
        return ans;
    }
};