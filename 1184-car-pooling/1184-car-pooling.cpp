class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        map<int,int> mp;// position -> passenger delta
        for(int i=0;i<n;i++){
            int start=trips[i][1];
            int end=trips[i][2];
            int passengers=trips[i][0];
            mp[start]+=passengers;
            mp[end]-=passengers;
        }
        int totpassengers=0;
        for(auto it:mp){
            totpassengers+=it.second;
            if(totpassengers>capacity){
                return false;
            }
        }
        return true;
    }
};