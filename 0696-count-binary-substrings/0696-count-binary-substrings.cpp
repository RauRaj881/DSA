class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int cnt=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                ans+=min(cnt,prev);
                prev=cnt;
                cnt=1;
            }
        }
        ans+=min(cnt,prev);
        return ans;
    }
};