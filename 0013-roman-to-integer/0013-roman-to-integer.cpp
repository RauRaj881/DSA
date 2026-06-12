class Solution {
public:
    int romanToInt(string s){
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        int prv=-1;
        for(int i=s.size()-1;i>=0;i--){
            int cr=mp[s[i]];
            if(cr>=prv){ans+=cr;}
            else{ans-=cr;}
            prv=cr;
        }
        return ans;
    }
};