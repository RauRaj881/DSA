class Solution {
public:
    int mySqrt(int x){
        if(x<=1){return x;}
        long long l=1,r=x;
        long long ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid==1LL*x){return mid;}
            else if(mid*mid<1LL*x){ans=mid;l=mid+1;}
            else{r=mid-1;}
        }
        return ans;
        
    }
};