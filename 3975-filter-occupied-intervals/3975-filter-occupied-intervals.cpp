class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){return a[0]<b[0];}
        return a[1]<b[1];
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oci, int frst,int fred){
        int n=oci.size();
        sort(oci.begin(),oci.end(),comp);
        int st=oci[0][0];
        int ed=oci[0][1];
        vector<vector<int>> mrg;
        for (int i = 1; i < n; i++) {
    if (oci[i][0] <= ed + 1) {
        ed = max(ed, oci[i][1]);
    } else {
        mrg.push_back({st, ed});
        st = oci[i][0];
        ed = oci[i][1];
    }
}
mrg.push_back({st, ed});
        vector<vector<int>> ans;

        for (auto &v : mrg) {
            long long l = v[0];
            long long r = v[1];

            if (r < frst || l > fred) {
                ans.push_back({(int)l, (int)r});
                continue;
            }

            if (l < frst) {
                ans.push_back({(int)l, frst - 1});
            }
            if (r > fred) {
                ans.push_back({fred + 1, (int)r});
            }
        }
        return ans; 
    }
};