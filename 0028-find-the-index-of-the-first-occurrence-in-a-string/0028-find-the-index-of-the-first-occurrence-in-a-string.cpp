class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size(),n2=needle.size();
        for(int i=0;i<=n1-n2;i++){
            int j=0;
            while(j<n2){
                if(haystack[i+j]==needle[j]){
                    j++;
                }
                else{break;}
            }
            if(j==n2){return i;}
        }
        return -1;
    }
};