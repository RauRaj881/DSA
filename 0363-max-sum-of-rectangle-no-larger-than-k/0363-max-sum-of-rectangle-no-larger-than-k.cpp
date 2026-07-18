class Solution {
public:
int kadane(vector<int>&tp,int k){
    int mx=INT_MIN;
    int cr=0;
    set<int> st;
    st.insert(0);
    for(int i=0;i<tp.size();i++){
        cr+=tp[i];
        auto it=st.lower_bound(cr-k);
        if(it!=st.end()){
            mx=max(mx,cr-*it);
        }
        st.insert(cr);
    }
    return mx;
}
    int maxSumSubmatrix(vector<vector<int>>& mat,int k){
        int n=mat.size();
        int m=mat[0].size();
        int ans=INT_MIN;
        for(int left=0;left<m;left++){
            vector<int> tp(n,0);
            for(int right=left;right<m;right++){
                for(int r=0;r<n;r++){
                    tp[r]+=mat[r][right];
                }
                ans=max(ans,kadane(tp,k));
            }
        }
        return ans;
    }
};