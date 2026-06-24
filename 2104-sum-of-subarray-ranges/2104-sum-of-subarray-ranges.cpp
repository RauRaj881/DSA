class Solution {
public:
    long long subArrayRanges(vector<int>& arr){
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
        vector<int> left2(n);
        vector<int> right2(n);
        stack<int> st2;
        for(int i=0;i<n;i++){
            while(!st2.empty()&&arr[i]>=arr[st2.top()]){st2.pop();}
            if(st2.empty()){left2[i]=i+1;}
            else{left2[i]=i-st2.top();}
            st2.push(i);
        }
        while(!st2.empty()){st2.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&arr[i]>arr[st2.top()]){st2.pop();}
            if(st2.empty()){right2[i]=n-i;}
            else{right2[i]=st2.top()-i;}
            st2.push(i);
        }
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long tp=-(1LL*arr[i]*left[i]*right[i])+(1LL*arr[i]*left2[i]*right2[i]);
            ans=(ans+tp);
        }
        return ans; 
    }
};