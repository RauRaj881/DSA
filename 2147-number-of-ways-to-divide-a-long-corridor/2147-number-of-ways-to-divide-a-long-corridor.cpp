class Solution {
public:
    int numberOfWays(string c) {
        int n=c.size();
        int cnts=0;
        for(auto it:c){
            if(it=='S'){cnts++;}
        }
        int mod=1e9+7;
        if(cnts%2!=0||cnts==0){return 0;};
        cnts=0;
        int prev=-1;
        long long ans=1;
        for(int i=0;i<n;i++){
           if(c[i]=='S'){
            cnts++;
            if(cnts%2!=0&&prev!=-1){
                long long d=i-prev;
                ans=(ans*d)%mod;
            }
            if(cnts%2==0){prev=i;}
           }
        }
        return (int)ans;
    }
};