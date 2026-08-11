class Solution {
public:
    bool isNStraightHand(vector<int>& hand,int sz){
        map<int,int> mp;
        for(auto it:hand){mp[it]++;}
        while(!mp.empty()){
            int st=mp.begin()->first;
            mp[st]--;
            if(mp[st]==0){mp.erase(st);}
            for(int i=1;i<sz;i++){
                if(!mp.count(st+i)){return false;}
                else{mp[st+i]--;if(mp[st+i]==0){mp.erase(st+i);}}
            }
        }
        return true;
    }
};