class Solution {
public:
typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i1=0,i2=0;
        vector<vector<int>> ans(k);
        priority_queue<P,vector<P>,greater<P>> pq;
        int sum0=nums1[0]+nums2[0];
        pq.push({sum0,{0,0}});
        int h=0;
        set<pair<int,int>> vis;
        vis.insert({0, 0});
        while(k--){
            auto p=pq.top();
            pq.pop();
            int y=p.second.first;
            int z=p.second.second;
            ans[h].push_back(nums1[y]);
            ans[h].push_back(nums2[z]);
            h++;
            if(y+1<n1&&!vis.count({y+1,z})){
                pq.push({nums1[y+1]+nums2[z],{y+1,z}});
                vis.insert({y+1,z});
            }
            if(z+1<n2&&!vis.count({y,z+1})){
                pq.push({nums1[y]+nums2[z+1],{y,z+1}});
                vis.insert({y,z+1});
            }
        }
        return ans;
    }
};