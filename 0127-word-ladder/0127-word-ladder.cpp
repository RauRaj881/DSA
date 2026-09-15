class Solution {
public:
    int ladderLength(string st,string ed,vector<string>& wl){
        int n=st.size();
        int m=wl.size();
        queue<string> q;
        q.push(st);
        unordered_set<string> s;
        for(auto it:wl){s.insert(it);}
        int cnt=1;
        while(!q.empty()){
            cnt++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string cr=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    string tp=cr;
                    for(int k=0;k<26;k++){
                        char ori=tp[j];
                        tp[j]=k+'a';
                        if(s.count(tp)){
                            q.push(tp);
                            s.erase(tp);
                            if(tp==ed){return cnt;}
                        }
                        tp[j]=ori;
                    }
                }
            }
        }
        return 0;
        
        
    }
};