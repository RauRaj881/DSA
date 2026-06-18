class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz){
        int n=hand.size();
        if(n%sz!=0){return false;}
        map<int,int> mp;
        for(auto it:hand){
            mp[it]++;
        }
        while(!mp.empty()){
            int st=mp.begin()->first;
            for(int i=0;i<sz;i++){
                int nt=st+i;
                if(!mp.count(nt)){return false;}
                mp[nt]--;
                if(mp[nt]==0){mp.erase(nt);}
            }
        }
        return true;
    }
};