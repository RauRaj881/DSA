class Solution {
public:
static bool cmp(string &a,string &b){
    int pos1=a.find(' ');
    int pos2=b.find(' ');
    string s1=a.substr(pos1+1);
    string s2=b.substr(pos2+1);
    if(s1==s2){return a<b;}
    return s1<s2;
}
    vector<string> reorderLogFiles(vector<string>& logs){
        int n=logs.size();
        vector<string> letters;
        vector<string> digits;
        for(int i=0;i<n;i++){
            int pos=logs[i].find(' ');
            if(logs[i][pos+1]>='0'&&logs[i][pos+1]<='9'){
                digits.push_back(logs[i]);
            }
            else{
                letters.push_back(logs[i]);
            }
        }
        sort(letters.begin(),letters.end(),cmp);
        for(auto it:digits){
            letters.push_back(it);
        }
        return letters;
    }
};