class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=1;
        int sh=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            if((i&(i-1))==0){sh++;}
            ans=(((ans<<sh)|i))%(mod);
            //ans=(ans|i)%(mod);
        }
        return ans;
    }
};