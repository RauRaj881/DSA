class Solution {
public:
long long f(long long index, vector<long long>& pow, map<long long,long long> &mp, vector<long long> &dp, long long lasttaken) {
    if (index < 0) return 0;
    if (dp[index] != -1) return dp[index];
    auto it = upper_bound(pow.begin(), pow.end(), pow[index] - 3);
    long long i = (it == pow.begin()) ? -1 : (it - pow.begin() - 1);

    long long take = (pow[index] * mp[pow[index]]) + f(i, pow, mp, dp, pow[index]);
    long long nottake = f(index - 1, pow, mp, dp, lasttaken);

    return dp[index] = max(take, nottake);
}

    long long maximumTotalDamage(vector<int>& power) {
        map<long long,long long> mp;
        for(int i=0;i<power.size();i++){
            mp[power[i]]++;
        }
        vector<long long> pow;
        for(auto it:mp){
            pow.push_back(it.first);
        }
        long long n=pow.size();
        sort(pow.begin(),pow.end());
        vector<long long> dp(n,-1);
        return f(n-1,pow,mp,dp,pow[n-1]+3);
    }
};