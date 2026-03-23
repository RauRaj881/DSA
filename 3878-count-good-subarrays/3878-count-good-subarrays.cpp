class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> rt(n,n);
        vector<int> lt(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&(nums[st.top()]|nums[i])>nums[st.top()]){
                rt[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&((nums[st2.top()]|nums[i])>nums[st2.top()]||nums[i]==nums[st2.top()])){
                lt[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(long long)(i-lt[i])*(rt[i]-i);
        }
        return ans;
    }
};