class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int,vector<int>> mp;
        int n=value.size();
        for(int i=0;i<n;i++){
            mp[limit[i]].push_back(value[i]);
        }
        long long ans=0;
        for(int lim=1;lim<=n;lim++){
            if(mp.find(lim)!=mp.end()){
                sort(mp[lim].rbegin(),mp[lim].rend());
                int size=mp[lim].size();
                for(int i=0;i<min(lim,size);i++){
                    ans+=mp[lim][i];
                }
            }
        }
        return ans;
    }
};