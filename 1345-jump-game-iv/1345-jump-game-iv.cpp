class Solution {
public:
    int minJumps(vector<int>& arr){
        int n=arr.size();
        unordered_set<int> s;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){mp[arr[i]].push_back(i);}
        s.insert(0);
        queue<int> q;
        q.push(0);
        int cnt=-1;
        while(!q.empty()){
            cnt++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
            int cr=q.front();
            q.pop();
            if(cr==n-1){return cnt;}
            int idx1=cr+1;
            int idx2=cr-1;
            if(idx1<n&&!s.count(idx1)){s.insert(idx1);q.push(idx1);}
            if(idx2>=0&&!s.count(idx2)){s.insert(idx2);q.push(idx2);}
            for(auto it:mp[arr[cr]]){
                s.insert(it);q.push(it);
            }
            mp.erase(arr[cr]);
            }
        }
        return cnt;
    }
};