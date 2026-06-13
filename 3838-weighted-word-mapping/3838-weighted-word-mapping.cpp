class Solution {
public:
    string mapWordWeights(vector<string>& ws, vector<int>& wts){
        int n=ws.size();
        string ans="";
        for(int i=0;i<n;i++){
            int cr=0;
            for(int j=0;j<ws[i].size();j++){
                cr+=wts[ws[i][j]-'a'];
            }
            cr=cr%26;
            cr=25-cr;
            ans+=(cr+'a');
        }
        return ans;
    }
};