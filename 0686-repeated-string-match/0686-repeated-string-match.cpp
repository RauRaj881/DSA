class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a;
        int count=1;
        while(s.size()<b.size()){
            s+=a;
            count++;
        }
        if(s.find(b) < s.length()){
            return count;
        }
        s+=a;
        if(s.find(b) < s.length()){return count+1;}
        return -1;
    }
};