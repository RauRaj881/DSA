class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n=s.size();
        unordered_map<char,int> mp;
        int l=0;
        int mx=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp.size()!=r-l+1){
                mp[s[l]]--;
                if(mp[s[l]]==0){mp.erase(s[l]);}
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};