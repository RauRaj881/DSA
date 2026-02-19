class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        //if(n==1){return 0;}
        int prev=0,curr=0;
        prev=1;
        int i=1;
        int ans=0;
        while(i<n){
            if(s[i]==s[i-1]){prev++;i++;}
            else{curr=1;break;}
        }
        i++;
        while(i<n){
            if(s[i]==s[i-1]){curr++;}
            else{
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
            i++;
        }
        ans+=min(prev,curr);
        return ans;
    }
};