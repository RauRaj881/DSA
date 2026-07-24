class Solution {
public:
    int minMovesToMakePalindrome(string s){
        int ans=0;
        while(s.size()>1){
            int n=s.size();
            char c=s[0];
            int match_idx=s.find_last_of(c);
            if(match_idx==0){ans+=n/2;}
            else{ans+=n-1-match_idx;s.erase(match_idx,1);}
            s.erase(0,1);
        }
        return ans;
    }
};