/*class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> presum(n);
        vector<int> sufsum(n);
        int sum=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            presum[i]=sum;
            if(nums[i]==0){s.insert(i);}
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            sufsum[i]=sum;
        }
        int ans=0;
        for(auto it:s){
            if(sufsum[it]==presum[it]){ans+=2;}
            else if(abs(sufsum[it]-presum[it])==1){
                ans++;
            }
        }
        return ans;
    }
};*/
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(auto it:nums){tot+=it;}
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0&&2*sum==tot){ans+=2;}
            else if(nums[i]==0&&abs(sum-(tot-sum))==1){ans+=1;}
        }
        return ans;
    }
};