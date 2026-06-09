class Solution {
public:
    bool rotateString(string s, string g){
        if(s.size()!=g.size()){return false;}
        string db=s+s;
        return db.find(g)!=string::npos;
    }
};