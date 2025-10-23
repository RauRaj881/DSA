class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        vector<int> v;
        for(int i=1;i<n;i++){
            int x=(int(s[i]-'0')+int(s[i-1]-'0'))%10;
            v.push_back(x);
        }
        while(v.size()>2){
            for(int i=1;i<v.size();i++){
                v[i-1]=(v[i]+v[i-1])%10;
            }
            v.erase(v.begin()+v.size()-1);
        }
        if(v[0]==v[1]){return true;}
        return false;
    }
};