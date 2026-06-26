class Solution {
public:
    int totalFruit(vector<int>& frt){
        int n=frt.size();
        int ans=1;
        unordered_map<int,int> mp;
        int l=0;
        for(int r=0;r<n;r++){
            mp[frt[r]]++;
            while(mp.size()>2){
                mp[frt[l]]--;
                if(mp[frt[l]]==0){mp.erase(frt[l]);}
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};