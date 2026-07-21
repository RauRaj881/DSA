class Solution {
public:
    bool canReach(vector<int>& st,vector<int>& trg){
        int tp1=(st[0]+st[1])%2;
        int tp2=(trg[0]+trg[1])%2;
        return tp1==tp2;
    }
};