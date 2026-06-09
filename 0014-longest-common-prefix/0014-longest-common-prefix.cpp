class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[n-1];
        string str;
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]){str+=(a[i]);}
            else {break;}
        }
        return str;
    }
};