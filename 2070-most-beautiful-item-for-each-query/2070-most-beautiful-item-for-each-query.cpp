class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& itms,vector<int>& qr){
        sort(itms.begin(),itms.end());
        int n=itms.size();
        int m=qr.size();
        vector<int> ans(m);
        vector<int> v(n,0);
        vector<int> p(n);
        p[0]=itms[0][0];
        v[0]=itms[0][1];
        for(int i=1;i<n;i++){
            p[i]=itms[i][0];
            v[i]=max(v[i-1],itms[i][1]);
        }
        for(int i=0;i<m;i++){
            int cr=qr[i];
            auto it=upper_bound(p.begin(),p.end(),cr);
            int idx=it-p.begin();
            if(idx>0){
                ans[i]=v[idx-1];
            }
            else{
                ans[i]=0;
            }
        }
        return ans;
    }
};