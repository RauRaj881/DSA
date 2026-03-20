class Solution {
public:
    int smallestBalancedIndex(vector<int>& ns){
        int n=ns.size();
        vector<long long> ad(n);
        vector<long long> pd(n);
        ad[0]=ns[0];
        for(int i=1;i<n;i++){
            ad[i]=ad[i-1]+ns[i];
        }
        pd[n-1]=ns[n-1];
        for(int i=n-2;i>=0;i--){
            int l = log10(pd[i+1]);
            int r = log10(ns[i]); 
            int sum = l + r;
            if(sum>14){pd[i]=1e16;}
            else{pd[i]=pd[i+1]*ns[i];}
        }
        for(int i=0;i<n;i++){
            long long f=i>0?ad[i-1]:0;
            long long s=i<n-1?pd[i+1]:1;
            if(f==s){return i;}
        }
        return -1;
    }
};