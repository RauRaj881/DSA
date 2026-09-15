class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int idx=0;idx<2*n;idx++){
            int i=idx%n;
            while(!st.empty()&&nums[st.top()]<nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};