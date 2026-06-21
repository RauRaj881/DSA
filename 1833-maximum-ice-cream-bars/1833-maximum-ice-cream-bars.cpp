class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins){
        int ans=0;
        int mx=0;
        for(auto it:costs){
            mx=max(mx,it);
        }
        vector<int> cnt(mx+1);
        for(auto it:costs){cnt[it]++;}
        for(int i=1;i<=mx;i++){
            ans+=min(coins/i,cnt[i]);
            coins-=min(cnt[i],coins/i)*i;
        }
        return ans;
    }
};