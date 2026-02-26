#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pre(n);
        for(int i=0;i<n;i++){
            if(nums[i]==target){nums[i]=1;}
            else{nums[i]=-1;}
        }
        ordered_set<int> st;
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        st.insert(0);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=st.order_of_key(pre[i]);
            st.insert(pre[i]);
        }
        return ans;
    }
};