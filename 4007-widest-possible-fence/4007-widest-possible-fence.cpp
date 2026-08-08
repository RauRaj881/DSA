#define ll long long
class Solution {
public:
    int maximumWidth(vector<int>& p){
        int n=p.size();
        unordered_map<ll,int> mp;
        for(auto it:p){mp[it]++;}
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        int mx=1;
        unordered_map<ll,int> ans;
        for(int i=0;i<v.size();i++){
            ll v1=v[i].first;
            int fr1=v[i].second;
            ans[v1]+=fr1;
            mx=max(mx,ans[v1]);
            ans[2*v1]+=fr1/2;
            mx=max(mx,ans[2*v1]);
            for(int j=i+1;j<v.size();j++){
                ll v2=v[j].first;
                int fr2=v[j].second;
                ll tot=v1+v2;
                ans[tot]+=min(fr1,fr2);
                mx=max(mx,ans[tot]);
            }
        }
        return mx;
    }
};