class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int n=strs.size();
        string s1=strs[0];
        for(int i=0;i<s1.size();i++){
            char c=s1[i];
            for(int j=1;j<n;j++){
                if(i==strs[j].size()||strs[j][i]!=c){
                    return s1.substr(0,i);
                }
            }
        }
        return s1;
    }
};