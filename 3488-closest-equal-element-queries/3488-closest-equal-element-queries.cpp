class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& qr){
        int q=qr.size();
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            if(mp[nums[qr[i]]].size()==1){ans[i]=-1;}
            else{
                auto it=lower_bound(mp[nums[qr[i]]].begin(),mp[nums[qr[i]]].end(),qr[i]);
                int sz=mp[nums[qr[i]]].size();
                int idx=it-mp[nums[qr[i]]].begin();
                int idx1=(idx-1+sz)%sz;
                int idx2=(idx+1)%sz;
                int d1=min(abs(qr[i]-mp[nums[qr[i]]][idx1]),n-abs(qr[i]-mp[nums[qr[i]]][idx1]));
                int d2=min(abs(qr[i]-mp[nums[qr[i]]][idx2]),n-abs(qr[i]-mp[nums[qr[i]]][idx2]));
                ans[i]=min(d1,d2);
            }
        }
        return ans;
    }
};