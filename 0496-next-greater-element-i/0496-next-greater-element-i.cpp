class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size();
        int n2=nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        //for(int i=0;i<n2;i++){mp[nums2[i]]=i;}
        for(int i=0;i<n2;i++){
            while(!st.empty()&&nums2[i]>st.top()){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> ans(n1);
        for(int i=0;i<n1;i++){
            if(mp.count(nums1[i])){ans[i]=mp[nums1[i]];}
            else{ans[i]=-1;}
        }
        return ans;
    }
};