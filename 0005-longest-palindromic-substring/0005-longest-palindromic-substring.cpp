class Solution {
public:
bool ispalin(int i,int j,string &s){
    int l=i,r=j;
    while(l<r){
        if(s[l]!=s[r]){return false;}
        r--;l++;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n=s.size();
        int x=0,y=0;
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ispalin(i,j,s)){
                    if(j-i+1>mx){
                        mx=j-i+1;
                        x=i;y=j;
                    }
                }
            }
        }
        return s.substr(x,y-x+1);
    }
};