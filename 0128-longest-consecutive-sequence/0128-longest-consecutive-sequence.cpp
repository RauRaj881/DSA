class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int mx=0;
        int prv=-1e9-3;
        int cnt=0;
        while(!mp.empty()){
            int cr=mp.begin()->first;
            if(cr==prv+1){cnt++;}
            else{mx=max(cnt,mx);cnt=1;}
            prv=cr;
            mp.erase(mp.begin());
        }
        mx=max(cnt,mx);
        return mx;
    }
};