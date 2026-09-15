class Solution {
public:
    int maxScore(vector<int>& c,int k){
        int n=c.size();
        int sz=n-k;
        int sm=0;
        int mn=INT_MAX,tot=0;
        for(int i=0;i<n;i++){
            sm+=c[i],tot+=c[i];
            if(i>=sz){sm-=c[i-sz];}
            if(i>=sz-1)mn=min(sm,mn);
        }
        return tot-mn;
    }
};