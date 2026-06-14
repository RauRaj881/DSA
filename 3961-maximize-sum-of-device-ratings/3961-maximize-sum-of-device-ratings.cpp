class Solution {
public:
    long long maxRatings(vector<vector<int>>& units){
        int m=units.size();
        int n=units[0].size();
        if (m == 1) {
            int mn = *min_element(units[0].begin(), units[0].end());
            return mn;
        }

        vector<long long> s(m), g(m);

        long long base = 0;

        for (int i = 0; i < m; i++) {
            int mn1 = INT_MAX, mn2 = INT_MAX;

            for (int x : units[i]) {
                if (x < mn1) {
                    mn2 = mn1;
                    mn1 = x;
                } else if (x < mn2) {
                    mn2 = x;
                }
            }

            s[i] = mn1;

            long long newRating;
            if (n == 1) newRating = 0;
            else newRating = mn2;

            g[i] = newRating - mn1;
            base += mn1;
        }

        int k = min_element(s.begin(), s.end()) - s.begin();

        long long A = 0;
        for (int i = 0; i < m; i++) {
            if (i == k) continue;
            A += max(0LL, g[i]);
        }

        long long bestCost = (long long)4e18;
        for (int d = 0; d < m; d++) {
            if (d == k) continue;

            bestCost = min(
                bestCost,
                (s[d] - s[k]) + max(0LL, g[d])
            );
        }

        long long ansGain = A;
        ansGain = max(ansGain, A + g[k] - bestCost);

        return base + ansGain;
    }
};