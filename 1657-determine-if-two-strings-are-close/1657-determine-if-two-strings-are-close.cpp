class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        if(n1!=n2){return false;}
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<n1;i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mp2[word2[i]]++;
        }
        vector<int> v1;
        vector<int> v2;
        if(mp1.size()!=mp2.size()){return false;}
        for(auto it:mp1){
            if(!mp2.count(it.first)){return false;}
            v1.push_back(it.second);
            v2.push_back(mp2[it.first]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2){return false;}
        return true;
    }
};