class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,mxl=0,mxf=0;
        unordered_map<char,int> mp;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            mxf=max(mxf,mp[s[r]]);
            while((r-l+1)-mxf>k){
                mp[s[l]]--;
                l++;
                //mxf=max(mxf,mp[s[r]]);
            }
        mxl=max(mxl,r-l+1);
        }
        return mxl;
    }
};