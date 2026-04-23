class Solution {
public:
    string frequencySort(string s){
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        sort(s.begin(),s.end(),[&](char x,char y){
            if(mp[x]==mp[y]){return x<y;}
            return mp[x]>=mp[y];
        });
        return s;
    }
};