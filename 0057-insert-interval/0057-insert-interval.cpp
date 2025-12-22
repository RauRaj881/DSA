class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& newintv) {
        int n=intv.size();
        if(n==0){return {newintv};}
        int l=newintv[0];
        int h=newintv[1];
        vector<vector<int>> ans;
        int idx=n;
        int low,high;
        for(int i=0;i<n;i++){
            int mn=intv[i][0];
            int mx=intv[i][1];
            if(!(mn>h||mx<l)){
                low=min(mn,l);
                high=max(mx,h);
                idx=i;break;
            }
        }
        if(idx!=n){
        for(int i=0;i<idx;i++){
            ans.push_back(intv[i]);
        }
        }
        for(int i=idx+1;i<n;i++){
            int mn=intv[i][0];
            int mx=intv[i][1];
            if(!(mn>high||mx<low)){
                low=min(mn,low);
                high=max(mx,high);
            }
            else{
                ans.push_back({low,high});
                low=mn;high=mx;
            }
        }
        if(idx!=n){ans.push_back({low,high});}
        if(idx==n){
            ans=intv;
            ans.push_back(newintv);
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};