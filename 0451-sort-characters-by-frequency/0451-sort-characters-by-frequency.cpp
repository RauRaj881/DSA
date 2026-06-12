class Solution {
public:
    string frequencySort(string s){
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            if(mp[a]==mp[b]){return b>a;}
            return mp[a]>mp[b];
        });
        return s; 
    }
};