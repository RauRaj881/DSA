class Solution {
public:
    int sumSubarrayMins(vector<int>& arr){
        int n=arr.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[i]<=arr[st.top()]){
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long cr=1LL*arr[i]*(nse[i]-i)*(i-pse[i]);
            ans=(ans+cr)%(mod);
        }
        return ans;
    }
};