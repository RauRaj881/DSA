class Solution {
public:
vector<string> ans;
void f(int i,vector<string>& phone,int n,string& s,string &d){
    if(i==n){ans.push_back(s);return;}
    for(int j=0;j<phone[d[i]-'0'].size();j++){
        s+=phone[d[i]-'0'][j];
        f(i+1,phone,n,s,d);
        s.pop_back();
    }
}

    vector<string> letterCombinations(string d){
        int n=d.size();
        string s="";
        vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,phone,n,s,d);
        return ans;
    }
};