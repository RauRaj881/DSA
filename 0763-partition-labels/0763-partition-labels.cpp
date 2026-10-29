class Solution {
public:
    vector<int> partitionLabels(string s){
        int n =s.size();
vector<int> ans;
int ed=0,st=0;
unordered_map<char,int> mp;
for(int i=0;i<n;i++){
mp[s[i]]=i;
    }
for(int i=0;i<n;i++){
ed=max(ed,mp[s[i]]);
if(ed==i){
ans.push_back(i-st+1);
st=i+1;
}
}
return ans;
    }
};