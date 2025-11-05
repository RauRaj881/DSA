class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int last=days[n-1];
        unordered_set<int> s(days.begin(),days.end());
        vector<int> dp(last+1);
        dp[0]=0;
        for(int day=1;day<=last;day++){
            if(!s.count(day)){
                dp[day]=dp[day-1];
            }
            else{
                dp[day]=min(dp[day-1]+costs[0],min(dp[max(0,day-7)]+costs[1],dp[max(0,day-30)]+costs[2]));
            }
        }
        return dp[last];
    }
};