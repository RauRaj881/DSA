class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<pair<int,int>>> pos(201);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]].push_back({i, j});
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int x = mat[i][j];

                if (x == 0) continue;

                bool ok = true;
                for (int val = x + 1; val <= 200 && ok; val++) {

                    for (auto &[r, c] : pos[val]) {

                        int d1 = abs(i - r);
                        int d2 = abs(j - c);
                        if (d1 <= x && d2 <= x) {
                            if (d1 == x && d2 == x)
                                continue;

                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) ans++;
            }
        }

        return ans;
        
    }
};