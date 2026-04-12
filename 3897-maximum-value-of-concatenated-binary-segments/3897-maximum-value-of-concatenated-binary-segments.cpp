class Solution {
public:
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    string x=string(a.first,'1')+string(a.second,'0');
    string y=string(b.first,'1')+string(b.second,'0');
    return (x+y)>(y+x);
}
    int maxValue(vector<int>& nums1, vector<int>& nums0){
        int n=nums1.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={nums1[i],nums0[i]};
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(int i=0;i<n;i++){
            string temp=string(v[i].first,'1')+string(v[i].second,'0');
            ans+=temp;
        }
        long long mod=1e9+7;
        long long vl=0;
        for(int i=0;i<ans.size();i++){
          vl = (vl * 2 + (ans[i] - '0')) % mod;
        }
        return vl;
    }
};