class Solution {
public:
    string lexGreaterPermutation(string s, string tar){
        string t=s;
        int n=s.size();
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        if(t<=tar){return "";}
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++){mp[s[i]-'a']++;}
        unordered_map<int,int> mp1=mp;
        string ans="";
        int lt=-1;
        for(int i=0;i<n;i++){
            int cr=tar[i]-'a';
            for(int j=cr+1;j<=25;j++){
                if(mp1[j]>0){lt=i;break;}
            }
            if(mp1[cr]==0){break;}
            else{mp1[cr]--;}
        }
        for(int i=0;i<lt;i++){
            ans+=(tar[i]);
            mp[tar[i]-'a']--;
        }
        int tcr=tar[lt]-'a';
        for(int i=tcr+1;i<=25;i++){
            if(mp[i]>0){ans+=i+'a';mp[i]--;break;}
        }
        for(int i=lt+1;i<n;i++){
            for(int j=0;j<=25;j++){
                if(mp[j]>0){ans+=j+'a';mp[j]--;break;}
            }
        }
        return ans;
    }
};