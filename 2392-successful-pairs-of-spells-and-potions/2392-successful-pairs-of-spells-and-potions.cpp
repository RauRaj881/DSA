class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> v(n);
        for(int i=0;i<n;i++){
            long long required=(spells[i]+success-1)/spells[i];
            auto it=lower_bound(potions.begin(),potions.end(),required);
            if(it==potions.end()){v[i]=0;}
            else{
            int index=it-potions.begin();
            v[i]=m-index;
            }
        }
        return v;
    }
};