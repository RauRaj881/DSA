class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
        }
        if(sum<0){return -1;}
        int index=0;
        int fuel=0;
        for(int i=0;i<n;i++){
            fuel+=gas[i]-cost[i];
            while(fuel<0){
                index=i+1;
                fuel=0;
                break;
            }
        }
        return index;
    }
};
