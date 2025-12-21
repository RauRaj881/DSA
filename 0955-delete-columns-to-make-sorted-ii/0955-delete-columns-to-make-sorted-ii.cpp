class Solution {
public:
bool IsSorted(vector<string> &curr){
    int n=curr.size();
    for(int i=1;i<n;i++){
        if(curr[i]<curr[i-1]){return false;}
    }
    return true;
}
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<string> SortedSoFar(n,"");
        int cnt=0;
        for(int i=0;i<m;i++){
            vector<string> curr=SortedSoFar;
            int d=0;
            for(int j=0;j<n;j++){
                curr[j]+=strs[j][i];
                if(j<n-1&&strs[j][i]<strs[j+1][i]){d++;}
            }
            if(d==n-1){return cnt;}
            if(IsSorted(curr)){
                SortedSoFar=curr;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};