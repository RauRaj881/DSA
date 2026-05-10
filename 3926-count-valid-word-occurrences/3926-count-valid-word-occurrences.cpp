class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& ch,vector<string>& qr){
        int n=ch.size();
        int q=qr.size();
        string s;
        for(auto it:ch){
            s+=it;
        }
        unordered_map<string,int> mp;
        string tp="";
        for(int i=0;i<s.size();i++){
            if (islower(s[i])) {
                tp += s[i];
            } 
            else if (s[i] == '-' && i > 0 && i < s.size() - 1 && islower(s[i-1]) && islower(s[i+1])) {
                tp += s[i];
            } 
            else {
                mp[tp]++;
                tp = "";
            }
        }
        mp[tp]++;
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            ans[i]=mp[qr[i]];
        }
        return ans;
        
    }
};