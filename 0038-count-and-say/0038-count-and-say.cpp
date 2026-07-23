class Solution {
public:
    string countAndSay(int n){
        string cr="1";
        for(int i=0;i<n-1;i++){
            int cnt=1;
            string tp;
            for(int j=1;j<cr.size();j++){
                if(cr[j]==cr[j-1]){cnt++;}
                else{tp+=string(1,cnt+'0')+cr[j-1];cnt=1;}
            }
            tp+=string(1,cnt+'0')+cr[cr.size()-1];
            cr=tp;
        }
        return cr;
    }
};