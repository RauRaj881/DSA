class Solution {
public:
    string minWindow(string s, string t){
        int n1=s.size();
        int n2=t.size();
        if(n2>n1){return "";}
        unordered_map<char,int> mp;
        for(auto it:t){mp[it]++;}
        int mn=n1,idx=-1;
        int l=0,cnt=0;
        int sz=mp.size();
        unordered_map<char,int> mp2;
        for(int r=0;r<n1;r++){
            mp2[s[r]]++;
            if(mp2[s[r]]==mp[s[r]]){cnt++;}
            while(cnt==sz&&l<=r){
                if(cnt==sz){if(mn>=r-l+1){mn=r-l+1;idx=l;}}
                mp2[s[l]]--;
                if(mp.count(s[l])&&mp2[s[l]]==mp[s[l]]-1){cnt--;}
                l++;
            }
        }
        if(idx==-1){return "";}
        return s.substr(idx,mn);
    }
};