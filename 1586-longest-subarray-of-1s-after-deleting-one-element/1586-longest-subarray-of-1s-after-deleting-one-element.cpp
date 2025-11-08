class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return 0;}
        else if(n==2){
            if(nums[0]==1&&nums[1]==1){return 1;}
            else if((nums[0]==1&&nums[1]!=1)||(nums[1]==1&&nums[0]!=1)){return 1;}
            else{return 0;}
        }
        vector<int> end(n);
        vector<int> start(n);
        end[0]=(nums[0]==1?1:0);
        start[n-1]=(nums[n-1]==1?1:0);
        for(int i=1;i<n;i++){
            if(nums[i]==1){end[i]=end[i-1]+1;}
            else{end[i]=0;}
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1){start[i]=start[i+1]+1;}
            else{start[i]=0;}
        }
        int ans=0;
        for (int i=0;i<n;i++){
            if (i==0){
                ans=max(ans,1+start[1]);
            } 
            else if(i==n-1){
                ans=max(ans,1+end[n-2]);
            } 
            else {
                if(nums[i-1]==1&&nums[i+1]==1){
                ans=max(ans,1+end[i-1]+start[i+1]);
                } 
                else{ 
                ans=max(ans,max(1+end[i-1],1+start[i+1]));
                }
            }
        }
        return ans-1;
    }
};