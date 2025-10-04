class Solution {
public:
void f(vector<string> &ans,string &digits,vector<string> &phone,string &s,int i){
    if(i==digits.size()){ans.push_back(s);return;}
    int x=digits[i]-'0';
    for(int j=0;j<phone[x].size();j++){
        string curr=phone[x];
        s+=curr[j];
        f(ans,digits,phone,s,i+1);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){return ans;}
        string s;
        vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(ans,digits,phone,s,0);
        return ans;
    }
};