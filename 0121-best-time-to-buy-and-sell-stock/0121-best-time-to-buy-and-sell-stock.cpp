class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxno=0;
        int minno=INT_MAX;
        int profit;
        for(int i=0;i<n;i++){
            minno=min(minno,prices[i]);
            profit=prices[i]-minno;
            maxno=max(maxno,profit);
        }
        return maxno;
    }
};