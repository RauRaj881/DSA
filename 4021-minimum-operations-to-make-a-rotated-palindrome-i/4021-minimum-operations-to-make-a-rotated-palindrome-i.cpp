class Solution {
public:
    int minOperations(string s){
        int n=s.size();
        int ans=INT_MAX;
        int x=(n+1)/2;
        for(int st=0;st<n;st++){
            int cr=st;
            int cnt=0;
            int st2=st;
            int st3=(st2+n-1)%n;
            while(cnt<n/2){
                int a=(abs(s[st2]-s[st3]))%26;
                int b=26-a;
                cr+=min(a,b);
                st2=(st2+1)%n;
                st3=(st3-1+n)%n;
                cnt++;
            }
            ans=min(ans,cr);
        }
        return ans;
    }
};