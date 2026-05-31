class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums){mp[it]++;}
        vector<int> ans;
        int i=0;
        while(i<n){
            int mex=0;
            while(mp[mex]>0){mex++;}
            if(mex==0){ans.push_back(0);mp[nums[i]]--;i++;}
            else{
                unordered_set<int> st;
                while(i<n){
                    if(nums[i]<mex){st.insert(nums[i]);}
                    mp[nums[i]]--;i++;
                    if(st.size()==mex){ans.push_back(mex);break;}
                }
            }
        }
        return ans;
    }
};