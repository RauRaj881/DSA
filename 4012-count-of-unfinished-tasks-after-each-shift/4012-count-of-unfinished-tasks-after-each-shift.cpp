#define ll long long
class Solution {
public:
    vector<int> countTasks(vector<int>& t,vector<int>& s){
        int n=s.size();
        int m=t.size();
        vector<ll> presm(m,0);
        vector<int> ans(n);
        presm[0]=t[0];
        for(int i=1;i<m;i++){
            presm[i]=t[i]+presm[i-1];
        }
        ll sm=0;
        for(ll i=0;i<n;i++){
            ll cn=sm+s[i];
            auto it=lower_bound(presm.begin(),presm.end(),cn);
            if(it==presm.end()){ans[i]=0;sm=0;}
            else{
                int idx=it-presm.begin();
                if(presm[idx]==cn){ans[i]=m-idx-1;if(idx==m-1){sm=0;}else{sm=cn;}}
                else{ans[i]=m-idx;sm=cn;}
            }
        }
        return ans;
    }
};