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


        while(!st.empty()){st.pop();}
        vector<int> left2(n);
        vector<int> right2(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]>=arr[st.top()]){st.pop();}
            if(st.empty()){left2[i]=i+1;}
            else{left2[i]=i-st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[i]>arr[st.top()]){st.pop();}
            if(st.empty()){right2[i]=n-i;}
            else{right2[i]=st.top()-i;}
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += 1LL * arr[i] * left2[i] * right2[i];
            ans -= 1LL * arr[i] * left[i] * right[i];
        }
        return ans; 
    }
};