class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n=capacity.size();
        vector<long long> v(n);
        v[0]=capacity[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+capacity[i];
        }
        unordered_map<long long, unordered_map<long long,long long>> mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp.count(capacity[i])&&mp[capacity[i]].count(v[i]-2*capacity[i])){
                ans+=mp[capacity[i]][v[i]-2*capacity[i]];
            }
            if(i >= 1) {
                long long prefix_prev = v[i-1];
                mp[capacity[i-1]][prefix_prev]++;
            }
        }
        return ans;
    }
};