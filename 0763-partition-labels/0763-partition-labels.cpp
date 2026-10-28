class Solution {
public:
    vector<int> partitionLabels(string s){
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int cnt=0;
        int st=0,ed=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            ed=max(ed,mp[s[i]]);
            if(i==ed){
                ans.push_back(i-st+1);
                st=i+1;
            }
        }
        return ans;
    }
};