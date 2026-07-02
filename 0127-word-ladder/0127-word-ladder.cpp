class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl){
        int n=wl.size();
        int m=bw.size();
        unordered_set<string> st;
        for(auto it:wl){st.insert(it);}
        if(!st.count(ew)){return 0;}
        queue<string> q;
        q.push(bw);
        int level=0;
        unordered_set<string> vis;
        vis.insert(bw);
        while(!q.empty()){
            level++;
            int sz=q.size();
            for(int k=0;k<sz;k++){
                string cr=q.front();
                q.pop();
            for(int i=0;i<m;i++){
                for(int j=0;j<26;j++){
                    char nw=j+'a';
                    string tp=cr;
                    tp[i]=nw;
                    if(tp==ew){return level+1;}
                    if(st.count(tp)&&!vis.count(tp)){q.push(tp);vis.insert(tp);}
                }
            }
            }
        }
        return 0;
        
    }
};