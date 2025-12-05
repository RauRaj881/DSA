/*class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        int n=points.size();
        for(int i=0;i<n;i++){
            mp[points[i][1]]++;
        }
        for(auto &it:mp){
            if(it.second<2){mp.erase(it);}
        }
        int ans=1;
        if(mp.size()<2){return 0;}
        for(auto it:mp){
            int x=it.second;
            ans*=(x*(x-1))/2;
        }
        return ans;
    }
};*/
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        for (auto &p : points) {
            mp[p[1]]++;
        }
        for (auto it = mp.begin(); it != mp.end();) {
            if (it->second < 2) {
                it = mp.erase(it);
            } else {
                ++it;
            }
        }
        long long mod=1e9+7;
        if (mp.size() < 2) return 0;
        long long ans = 0;
        long long edgessum = 0;
        for (auto it : mp) {
            long long x = it.second;
            long long edges = (x * (x - 1) / 2) % mod;
            ans = (ans + edges * edgessum) % mod;
            edgessum = (edgessum + edges) % mod;
        }
        return ans % mod;
    }
};
