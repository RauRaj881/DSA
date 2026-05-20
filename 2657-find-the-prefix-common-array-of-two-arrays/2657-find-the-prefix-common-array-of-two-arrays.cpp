class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        unordered_map<int,int> mp;
        int n=A.size();
        vector<int> ans(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==0){cnt++;}
            mp[B[i]]--;
            if(mp[B[i]]==0){cnt++;}
            ans[i]=cnt;
        }
        return ans;
    }
};