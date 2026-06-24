class Solution {
public:
    int sumSubarrayMins(vector<int>& arr){
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<=arr[st.top()]){st.pop();}
            if(st.empty()){left[i]=i+1;}
            else{left[i]=i-st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[i]<arr[st.top()]){st.pop();}
            if(st.empty()){right[i]=n-i;}
            else{right[i]=st.top()-i;}
            st.push(i);
        }
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long tp=(1LL*arr[i]*left[i]*right[i]);
            ans=(ans+tp)%mod;
        }
        return ans;
    }
};