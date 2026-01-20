class Solution {
public:
static bool comp(vector<int> &a,vector<int>&b){
    if(a[0]==b[0])return a[1]>b[1];
    return a[0]<b[0];
}
    int maxEnvelopes(vector<vector<int>>& el) {
        sort(el.begin(),el.end(),comp);
        int n=el.size();
        vector<int> tails;
        for(int i=0;i<n;i++){
            int h=el[i][1];
            auto it=lower_bound(tails.begin(),tails.end(),h);
            if(it==tails.end()){tails.push_back(h);}
            else{*it=h;}
        }
        return tails.size();
    }
};