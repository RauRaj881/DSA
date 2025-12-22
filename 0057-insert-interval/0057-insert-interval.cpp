class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newinte) {
        int n=inte.size();
        vector<vector<int>> v;
        int i=0;
        while(i<n && inte[i][1]<newinte[0]){
            v.push_back({inte[i][0],inte[i][1]});
            i++;
        }
         while(i<n && inte[i][0]<=newinte[1]){
           newinte[0]=min(inte[i][0],newinte[0]);
           newinte[1]=max(inte[i][1],newinte[1]);
            i++;
        }
        v.push_back({newinte[0],newinte[1]});
        while(i<n){
            v.push_back({inte[i][0],inte[i][1]});
            i++;
        }
        return v;
    }
};