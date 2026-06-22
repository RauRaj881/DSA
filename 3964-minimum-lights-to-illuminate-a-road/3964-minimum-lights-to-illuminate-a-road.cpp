class Solution {
public:
    int minLights(vector<int>& lights){
        int n=lights.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);

                diff[l]++;
                if (r + 1 < n)
                    diff[r + 1]--;
            }
        }

        int ans = 0;
        int cur = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];

            if (cur == 0) {
                len++;
            } else {
                ans += (len + 2) / 3;
                len = 0;
            }
        }

        ans += (len + 2) / 3;

        return ans;
    }
};