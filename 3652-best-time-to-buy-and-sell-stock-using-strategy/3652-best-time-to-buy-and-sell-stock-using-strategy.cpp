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
// new implementation method of sliding window question-converting into two variables(base +slide) and doing operations on base and slide according to the variations in base and slide in O(1) times.
class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n=p.size();
        long long base=0;
        for(int i=0;i<n;i++){
            base+=p[i]*s[i];
        }
        long long ans=base;
        for(int i=0;i<k;i++){
            base-=p[i]*s[i];
        }
        long long slide=0;
        for(int i=k/2;i<k;i++){
            slide+=p[i];
        }
        ans=max(ans,base+slide);
        for(int i=k;i<n;i++){
            base-=p[i]*s[i];
            base+=p[i-k]*s[i-k];
            slide+=p[i];
            slide-=p[i-k/2];
            ans=max(ans,slide+base);
        }
        return ans;
    }
};