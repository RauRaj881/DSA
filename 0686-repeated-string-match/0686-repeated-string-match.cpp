class Solution {
public:
    int repeatedStringMatch(string a, string b){
        string tp=a;
        int cnt=1;
        while(tp.size()<b.size()){
            tp+=a;
            cnt++;
        }
        if(tp.find(b)<tp.length()){return cnt;}
        tp+=a;
        if(tp.find(b)<tp.length()){return cnt+1;}
        return -1;
    }
};