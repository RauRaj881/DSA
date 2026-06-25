class Solution {
public:
    int maximumScore(vector<int>& nums, int k){
        int n=nums.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if((i<=k&&nse[i]>k)||(i>k&&pse[i]<k)){
                ans=max(ans,nums[i]*(nse[i]-pse[i]-1));
            }
        }
        return ans;
    }
};