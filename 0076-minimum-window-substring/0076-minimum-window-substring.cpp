class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        int cnt=0;
        int l=0,r=0;
        int startl=-1,minr=0;
        int minlength=m;
        while(r<m){
            char c=s[r];
            if(mp[c]>0){cnt++;};
            mp[c]--;
            while(l<=r&&cnt>=n){
                if(r-l+1<=minlength){minlength=r-l+1;startl=l;}
                mp[s[l]]++;
                if(mp[s[l]]>0){cnt--;}
                l++;
            }
            r++;
        }
        if(s==t){return s;}
        else if(startl==-1){return s.substr(0,0);}
        return s.substr(startl,minlength); 
    }
};