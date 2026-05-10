class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& ch,vector<string>& qr){
        int q=qr.size();
        string s;
        for(auto it:ch){
            s+=it;
        }
        int n=s.size();
        unordered_map<string,int> mp;
        string tp="";
        for(int i=0;i<s.size();i++){
            if(islower(s[i])){
                tp+=s[i];
            }
            else if(s[i]=='-'){
                if(i>0&&i<n-1){
                    if(islower(s[i-1])&&islower(s[i+1])){
                        tp+=s[i];
                    }
                    else{mp[tp]++;tp="";}
                }
                else{mp[tp]++;tp="";}
            }
            else{mp[tp]++;tp="";}
        }
        mp[tp]++;
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            ans[i]=mp[qr[i]];
        }
        return ans;
    }
};