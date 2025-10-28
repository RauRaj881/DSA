class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int tot=numBottles;
        int ans=0;
        int empty=0;
        while(tot>0){
            ans+=tot;
            int x=tot+empty;
            tot=0;
            if(x>=numExchange){
                tot=1;
                empty=x-numExchange;
                numExchange++;
            }
        }
        return ans;   
    }
};