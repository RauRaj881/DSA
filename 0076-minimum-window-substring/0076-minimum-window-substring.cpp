class Solution {
public:
    string minWindow(string s, string t){
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> mp;
        for(auto it:t){mp[it]++;}
        int sz=mp.size();
        //int cnt=0;
        int cr=0;
        int l=0;
        int len=1e6,st=-1;
        unordered_map<char,int> mp2;
        for(int r=0;r<s.size();r++){
            mp2[s[r]]++;
            if(mp2[s[r]]==mp[s[r]]){cr++;}
            while(cr>=sz&&l<=r){
                if(r-l+1<len){len=r-l+1;st=l;}
                mp2[s[l]]--;
                if(mp2[s[l]]+1==mp[s[l]]){cr--;}
                l++;
            }
        }
        if(st==-1){return "";}
        return s.substr(st,len);
    }
};