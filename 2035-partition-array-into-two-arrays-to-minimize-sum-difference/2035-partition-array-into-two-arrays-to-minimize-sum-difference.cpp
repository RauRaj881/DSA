class Solution {
public:
void f(vector<vector<int>> &lt,vector<vector<int>>& rt,vector<int>& nums,int tot){
    int n=nums.size();
    for(int i=0;i<(1<<(n/2));i++){
        int sz=0;
        int sm1=0,sm2=0;
        for(int j=0;j<n/2;j++){
            if((i&(1<<j))!=0){sz++;sm1+=nums[j];sm2+=nums[n/2+j];}
        }
        lt[sz].push_back(sm1);
        rt[sz].push_back(sm2);
    }
}
    int minimumDifference(vector<int>& nums){
        int n=nums.size();
        int tot=0;
        for(auto it:nums){tot+=it;}
        vector<vector<int>> lt(n/2+1);
        vector<vector<int>> rt(n/2+1);
        f(lt,rt,nums,tot);
        for(int i=0;i<=n/2;i++){
            sort(rt[i].begin(),rt[i].end());
        }
        int mn=INT_MAX;
        for(int sz=0;sz<=n/2;sz++){
            for(auto it:lt[sz]){
                auto it2=lower_bound(rt[n/2-sz].begin(),rt[n/2-sz].end(),(tot-2*it)/2);
                if(it2!=rt[n/2-sz].end()){
                    int idx=it2-rt[n/2-sz].begin();
                    int sm1=it,sm2=rt[n/2-sz][idx];
                    int sb1=sm1+sm2;
                    int sb2=tot-sb1;
                    mn=min(mn,abs(sb1-sb2));
                }
                if(it2!=rt[n/2-sz].begin()){
                    int idx=it2-rt[n/2-sz].begin()-1;
                    int sm1=it,sm2=rt[n/2-sz][idx];
                    int sb1=sm1+sm2;
                    int sb2=tot-sb1;
                    mn=min(mn,abs(sb1-sb2));
                }
            }
        }
        return mn;
    }
};