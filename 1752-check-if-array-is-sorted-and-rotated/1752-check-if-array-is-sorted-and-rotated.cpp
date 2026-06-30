class Solution {
public:
    bool check(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            int idx=i+1;
            while(cnt<n-1){
                idx=(idx)%n;
                int idx2=(idx-1+n)%n;
                if(nums[idx]>=nums[idx2]){cnt++;idx++;}
                else{break;}
            }
            if(cnt==n-1){return true;}
        }
        return false;
        
    }
};