class Solution {
public:
string rotate(string&p,int b){
    int n=p.size();
    string last=p.substr(0,n-b);
    string first=p.substr(n-b,b);
    return first+last;
    }
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        queue<string> q;
        q.push(s);
        unordered_map<string,int> vis;
        vis[s]=1;
        string mini=s;
        while(!q.empty()){
            string p=q.front();
            mini=min(mini,p);
            q.pop();
                string rotated=rotate(p,b);
                if(!vis.count(rotated)){
                    vis[rotated]=1;
                    q.push(rotated);
                }
                for(int i=1;i<n;i+=2){
                   p[i] = char((p[i] - '0' + a) % 10 + '0');
                }
                if(!vis.count(p)){
                    vis[p]=1;
                    q.push(p);
                }
        }
        return mini;
    }
};