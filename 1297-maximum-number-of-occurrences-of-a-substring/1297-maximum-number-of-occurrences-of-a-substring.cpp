class Solution {
public:
    int maxFreq(string s, int mxLt, int mnSz, int mxSz){
        unordered_map<string,int> mp;
        int l=0;
        unordered_map<char,int> tp;
        for(int r=0;r<s.size();r++){
            tp[s[r]]++;
            if(r-l+1<mnSz){continue;}
            while(r-l+1>mnSz||tp.size()>mxLt){
                tp[s[l]]--;
                if(tp[s[l]]==0){tp.erase(s[l]);}
                l++;
            }
            if(tp.size()<=mxLt&&r-l+1==mnSz)mp[s.substr(l,r-l+1)]++;
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};