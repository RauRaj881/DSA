//TLE
/*class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n1=s.size();
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int i1=0,i2=0;
            string t=words[i];
            int n2=t.size();
        while(i1<n1&&i2<n2){
            if(s[i1]==t[i2]){
                i1++;i2++;
            }
            else{
                i1++;
            }
            if(i2==n2){cnt++;}
        }
        }
        return cnt;        
    }
};*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n1=s.size();
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<n1;i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string t=words[i];
            int n2=t.size();
            int i1=0,i2=0,prev=-1;
            for(int j=0;j<n2;j++){
                char c=t[j];
                if(!mp.count(c)){cnt--;break;}
                vector<int>& v=mp[c];
                auto it=upper_bound(v.begin(),v.end(),prev);
                if(it==v.end()){cnt--;break;}
                else{prev=*it;}
            }
            cnt++;
        }
        return cnt;
    }
};