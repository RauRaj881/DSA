class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s2.size();
        if(n==1) return s1[0]==s2[0];
        vector<string> v(n);
        for(int i=0;i<=1;i++){
            string s="";
            for(int j=i;j<n;j+=2){
                s+=s1[j];
            }
            sort(s.begin(),s.end());
            v[i]=s;
        }
        for(int i=0;i<2;i++){
            string s="";
            for(int j=i;j<n;j+=2){
                //string p=s1[j];
                s+=s2[j];
            }
            sort(s.begin(),s.end());
            if(s!=v[i]) return false;
        }
        return true;
        
    }
};