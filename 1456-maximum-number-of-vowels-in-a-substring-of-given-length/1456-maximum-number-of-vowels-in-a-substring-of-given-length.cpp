class Solution {
public:
    int maxVowels(string s, int k){
        int n=s.size();
        int ans=0;
        int mx=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){cnt++;}
            if(i-k>=0){
                if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='o'||s[i-k]=='i'||s[i-k]=='u'){
                    cnt--;
                }
            }
            if(i>=k-1){mx=max(mx,cnt);}
        }
        return mx;
    }
};