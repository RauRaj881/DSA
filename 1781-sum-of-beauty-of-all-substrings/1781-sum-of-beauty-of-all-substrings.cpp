class Solution {
public:
    int beautySum(string s){
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> v(26,0);
            for(int j=i;j<n;j++){
                int c=s[j]-'a';
                v[c]++;
                int mx = 0;
                int mn = INT_MAX;
                for(int k = 0; k < 26; k++) {
                    if(v[k] > 0) {
                        mx = max(mx, v[k]);
                        mn = min(mn, v[k]);
                    }
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};