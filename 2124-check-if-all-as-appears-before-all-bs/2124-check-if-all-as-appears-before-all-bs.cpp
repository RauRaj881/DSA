class Solution {
public:
    bool checkString(string s){
        int n=s.size();
        int idxa=-1,idxb=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){idxa=i;}
            else if(idxb==-1){idxb=i;}
        }
        if(idxa==-1||idxb==-1){return true;}
        return idxa<=idxb;
        
    }
};