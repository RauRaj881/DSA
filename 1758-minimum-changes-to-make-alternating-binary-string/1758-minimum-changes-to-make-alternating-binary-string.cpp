class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int cnt1=0;
        int st1=1;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'!=st1){cnt1++;}
            st1=1-st1;
        }
        int cnt2=0;
        int st2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'!=st2){cnt2++;}
            st2=1-st2;
        }
        ans=min(cnt1,cnt2);
        return ans;
        
    }
};