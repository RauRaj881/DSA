/*class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        int l=0,r=k-1;
        int maxno=INT_MIN;
        int x=0;
        for(int i=0;i<n;i++){
            x+=prices[i]*strategy[i];
        }
        maxno=max(maxno,x);
        while(r<n){
            int tot=x;
            for(int i=l+k/2;i<l+k;i++){
                tot-=prices[i]*strategy[i];
                 tot-=prices[i-k/2]*strategy[i-k/2];
            if(i>=l+k/2&&i<l+k){
                tot+=prices[i];
            }
        }
               maxno=max(maxno,tot);
            l++;r++;
        }
        return maxno; 
    }
};*/
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long n=prices.size();
        long long base=0;
        for(int i=0;i<n;i++){
            base+=prices[i]*strategy[i];
        }
        long long ans=base;
        for(int i=0;i<k;i++){
            base-=prices[i]*strategy[i];
        }
        long long slide=0;
        for(int i=k/2;i<k;i++){
            slide+=prices[i];
        }
        ans=max(ans,base+slide);
        for(int i=k;i<n;i++){
            base-=prices[i]*strategy[i];
            base+=prices[i-k]*strategy[i-k];
            slide+=prices[i];
            slide-=prices[i-k/2];
            ans=max(ans,base+slide);
        }
        return ans;
    }
};