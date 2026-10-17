class Solution {
public:
    bool validPalindrome(string s){
        int n=s.size();
        int i=0,j=n-1;
        int cnt1=0;
        while(i<=j){
            if(s[i]!=s[j]){cnt1++;i++;}
            else{i++;j--;}
        }
        int cnt2=0;
        i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]){cnt2++;j--;}
            else{i++;j--;}
        }
        return cnt1<=1||cnt2<=1;
    }
};