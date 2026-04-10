class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<=k-2;i++){mp[nums[i]]++;}
        for(int i=k-1;i<n;i++){
            mp[nums[i]]++;
            if(i>k-1){mp[nums[i-k]]--;}
            vector<pair<int,int>> v;
            for(auto it:mp){
                v.push_back({it.second,it.first});
            }
            sort(v.begin(),v.end(),greater<pair<int,int>>());
            int sm=0;
            int j=0;
            int tx=x;
            while(tx--&&j<v.size()){
                sm+=(v[j].second)*(v[j].first);j++;
            }
            ans.push_back(sm);
        }
        return ans;
    }
};