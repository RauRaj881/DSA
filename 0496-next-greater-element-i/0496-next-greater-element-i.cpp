class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> nge(n2,-1);
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<n2;i++){mp[nums2[i]]=i;}
        for(int i=0;i<n2;i++){
            while(!st.empty()&&nums2[i]>nums2[st.top()]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans(n1);
        for(int i=0;i<n1;i++){
            int idx=mp[nums1[i]];
            ans[i]=nge[idx]==-1?-1:nums2[nge[idx]];
        }
        return ans;
    }
};