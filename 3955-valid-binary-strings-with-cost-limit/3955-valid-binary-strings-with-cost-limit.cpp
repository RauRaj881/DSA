class Solution {
public:
    vector<string> generateValidStrings(int n, int k){
        vector<string> ans;
        for (int mask = 0; mask < (1 << n); mask++) {
            string s(n, '0');
            int cost = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    s[i] = '1';
                    cost += i;

                    if (i > 0 && s[i - 1] == '1') {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok && cost <= k) {
                ans.push_back(s);
            }
        }

        return ans;
        
    }
};