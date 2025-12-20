class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            string a=strs[j];
            string b=strs[j-1];
            if(a[i]<b[i]){cnt++;break;}
        }
        }
        return cnt;
    }
};