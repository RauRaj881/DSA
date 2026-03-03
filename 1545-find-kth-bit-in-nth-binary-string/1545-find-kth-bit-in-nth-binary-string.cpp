class Solution {
public:
string get(string lt){
    string tp=lt;
    for(int i=0;i<lt.size();i++){
        if(tp[i]=='0'){tp[i]='1';}
        else{tp[i]='0';}
    }
    reverse(tp.begin(),tp.end());
    return lt+"1"+tp;
}
    char findKthBit(int n, int k) {
        string ans="0";
        string lt="0";
        string cr="0";
        for(int i=2;i<=n;i++){
            cr=get(lt);
            ans=cr;
            lt=cr;
        }
        return cr[k-1];
    }
};