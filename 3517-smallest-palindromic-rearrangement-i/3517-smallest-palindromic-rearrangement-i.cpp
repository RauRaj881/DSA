class Solution {
public:
    string smallestPalindrome(string s){
        int n=s.size();
        string ans(n,'#');
        vector<int> v(26,0);
        for(auto it:s){v[it-'a']++;}
        int i=0;
        int k=0;
        while(i<=n/2){
            for(int j=k;j<26;j++){
                if(v[j]>=2){ans[i]=j+'a';ans[n-i-1]=j+'a';v[j]-=2;k=j;break;}
            }
            i++;
        }
        if(n%2==1){
            for(int i=0;i<26;i++){
                if(v[i]==1){ans[n/2]=i+'a';}
            }
        }
        return ans;
    }
};