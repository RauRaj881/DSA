class Solution {
public:
    bool isAnagram(string s, string t) {
        /*int h=0;
        int m=t.length();
        if(s.length()!=t.length()){return 0;}
        for(int i=0;i<s.length();i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){h++;t.erase(j,1);m--;break;}
            }
        }
        if(h==s.length()){return 1;}
        else{return 0;}*/
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){return 1;}
        else {return 0;}
    }
};