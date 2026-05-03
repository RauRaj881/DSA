class Solution {
public:
    int sumOfPrimesInRange(int n){
        vector<int> sieve(1001,-1);
        sieve[1]=0;
        for(int i=2;i<=1000;i++){ 
            for(int j=i*i;j<=1000;j+=i){ 
                if(j<=1000){sieve[j]=1;} 
            } 
        } 
        string s=""; 
        int x=n; 
        while(x!=0){ 
            s+=char(x%10+'0'); 
            x/=10; 
        } 
        int m=stoi(s); 
        int mn=min(n,m); 
        int mx=max(n,m); 
        int ans=0; 
        for(int i=mn;i<=mx;i++){ 
            if(sieve[i]==-1){ans+=i;} 
        }
        return ans;
    }
};