class Solution {
public:
void storesm(vector<int>&nums,vector<vector<int>>&left,vector<vector<int>>&right,int tot){
    int n=nums.size();
    for(int i=0;i<=(1<<(n/2));i++){
        int sz=0;
        int sm1=0,sm2=0;
        for(int j=0;j<n/2;j++){
            if((i&(1<<j))!=0){sz++;sm1+=nums[j];sm2+=nums[j+n/2];}
        }
        left[sz].push_back(sm1);
        right[sz].push_back(sm2);
    }
}
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(auto it:nums){
            tot+=it;
        }
        vector<vector<int>> left(n/2+1);
        vector<vector<int>> right(n/2+1);
        storesm(nums,left,right,tot);
        for(int i=0;i<=n/2;i++){
            sort(right[i].begin(),right[i].end());
        }
        int mn=1e9;
        for(int sz=0;sz<=n/2;sz++){
            for(auto it2:left[sz]){
                auto it3=lower_bound(right[n/2-sz].begin(),right[n/2-sz].end(),(tot-2*it2)/2);
                if(it3!=right[n/2-sz].end()){
                    int idx=it3-right[n/2-sz].begin();
                    int val=right[n/2-sz][idx];
                    mn=min(mn,abs(tot-2*(it2+val)));
                }
                if(it3!=right[n/2-sz].begin()){
                    int idx=it3-right[n/2-sz].begin()-1;
                    int val=right[n/2-sz][idx];
                    mn=min(mn,abs(tot-2*(it2+val)));
                }
            }
        }
        return mn;
    }
};