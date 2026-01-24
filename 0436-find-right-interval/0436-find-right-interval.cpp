class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& iv) {
        int n=iv.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=iv[i][0];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            auto it=lower_bound(v.begin(),v.end(),make_pair(iv[i][1],-1e6));
            if(it==v.end()){ans[i]=-1;}
            else{int idx=it-v.begin();ans[i]=v[idx].second;}
        }
        return ans;
    }
};