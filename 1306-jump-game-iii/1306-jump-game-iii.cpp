class Solution {
public:
    bool canReach(vector<int>& arr,int st){
        int n=arr.size();
        unordered_set<int> s;
        s.insert(st);
        queue<int> q;
        q.push(st);
        while(!q.empty()){
            int cr=q.front();
            q.pop();
            if(arr[cr]==0){return true;}
            int idx1=cr+arr[cr];
            int idx2=cr-arr[cr];
            if(idx1<n&&!s.count(idx1)){s.insert(idx1);q.push(idx1);}
            if(idx2>=0&&!s.count(idx2)){s.insert(idx2);q.push(idx2);}
        }
        return false;
    }
};