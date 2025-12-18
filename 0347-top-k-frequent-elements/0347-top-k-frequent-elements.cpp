class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> v;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){cnt++;}
            else{
                v.push_back({cnt,nums[i-1]});
                cnt=1;
            }
        }
        v.push_back({cnt,nums[n-1]});
        sort(v.rbegin(),v.rend());
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=v[i].second;
        }
        return ans;
    }
};