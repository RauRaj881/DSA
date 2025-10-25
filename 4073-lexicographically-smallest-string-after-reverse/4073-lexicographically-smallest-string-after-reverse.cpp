class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for(int i=0;i<n;i++){
            string first=s.substr(0,i+1);
            string last=s.substr(i+1,n-i);
            reverse(first.begin(),first.end());
            string final=first+last;
            ans=min(ans,final);
        }
        for(int i=0;i<n;i++){
            string first=s.substr(0,i+1);
            string last=s.substr(i+1,n-i);
            reverse(last.begin(),last.end());
            string final=first+last;
            ans=min(ans,final);
        }
        return ans;
    }
};