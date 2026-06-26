class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,int idxdf,int vldf){
        int n=nums.size();
        multiset<int> st;
        for(int i=0;i<n;i++){
            if(i>idxdf){st.erase(nums[i-idxdf-1]);}
            auto it=st.lower_bound(nums[i]-vldf);
            if(it!=st.end()&&*it<=nums[i]+vldf){return true;}
            st.insert(nums[i]);
        }
        return false;
    }
};