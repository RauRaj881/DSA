class Solution {
public:
bool isvalid(string s){
    if(s.empty()){return false;}
    int m=s.size();
    for(int i=0;i<m;i++){
        int x=(int)(s[i]);
        if(!((x>=65&&x<=90)||(x>=97&&x<=122)||x==95||(x>=48&&x<=57))){
            return false;
        }
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& bL, vector<bool>& isA) {
        int n=code.size();
        vector<pair<string,string>> v;
        for(int i=0;i<n;i++){
            if(isvalid(code[i])&&(bL[i]=="electronics"||bL[i]=="grocery"||bL[i]=="pharmacy"||bL[i]=="restaurant")&&isA[i]==true){
                v.push_back({bL[i],code[i]});
            }
        }
        sort(v.begin(),v.end());
        vector<string> ans;
        int k=v.size();
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};