class Solution {
public:
    char kthCharacter(int k) {
        string tp="a";
        for(int i=0;i<9;i++){
                string cr=tp;
                for(int j=0;j<cr.size();j++){
                    int nm=cr[j]-'a';
                    nm=(nm+1)%26;
                    cr[j]=nm+'a';
                }
                tp+=cr;
        }
        return tp[k-1];
    }
};