class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr){
        int n=arr.size();
        vector<int> tp=arr;
        sort(tp.begin(),tp.end());
        unordered_map<int,int> mp;
        int cr=1;
        for(int i=0;i<n;i++){
            if(i>0&&tp[i]==tp[i-1]){continue;}
            else{mp[tp[i]]=cr;cr++;}
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};