class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        if(n==1){return 0;}
        int cnt=1;
        int mx=neededTime[0];
        int tot=neededTime[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){tot+=neededTime[i];cnt++;mx=max(mx,neededTime[i]);}
            else{
                if(cnt>1){ans+=tot-mx;}
                tot=neededTime[i];cnt=1;mx=neededTime[i];
            }
        }
        if(cnt>1){ans+=tot-mx;}
        return ans;
    }
};