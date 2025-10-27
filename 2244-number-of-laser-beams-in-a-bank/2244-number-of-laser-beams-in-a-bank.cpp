class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0,tot=0;
        int m=bank[0].length();
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            string curr=bank[i];
            for(int j=0;j<m;j++){
                if(curr[j]=='1'){cnt++;}
            }
            ans+=cnt*tot;
            if(cnt>0){tot=cnt;}
        }
        return ans;
    }
};