class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int cnt=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                int x=st.top();
                st.pop();
                if((i-x)>=2){cnt++;}
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                int x=st.top();
                st.pop();
                if((x-i)>=2){cnt++;}
            }
            st.push(i);
        }
        return cnt;
    }
};