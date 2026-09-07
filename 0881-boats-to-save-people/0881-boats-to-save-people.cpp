class Solution {
public:
    int numRescueBoats(vector<int>& ppl,int lmt){
        int n=ppl.size();
        int ans=0;
        int i=0,j=n-1;
        sort(ppl.begin(),ppl.end());
        while(i<j){
            if(ppl[i]+ppl[j]<=lmt){
                i++;
                j--;
            }
            else{j--;}
            ans++;
        }
        if(i==j){ans++;}
        return ans;
    }
};