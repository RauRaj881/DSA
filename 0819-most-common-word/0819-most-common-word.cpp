class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned){
        int n=paragraph.size();
        unordered_set<string> st;
        unordered_map<string,int> mp;
        for(auto it:banned){
            st.insert(it);
        }
        int i=0;
        while(i<n){
            if((islower(paragraph[i])||isupper(paragraph[i]))){
                string cr="";
            while(i<n&&(islower(paragraph[i])||isupper(paragraph[i]))){
                cr+=tolower(paragraph[i]);
                i++;
            }
            mp[cr]++;
            }
            else{
                i++;
            }
        }
        int mx=0;
        string ans="";
        for(auto it:mp){
            if(!st.count(it.first)){
                if(it.second>mx){
                    mx=it.second;
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};