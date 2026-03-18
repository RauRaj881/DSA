class Solution {
public:
    int longestArithmetic(vector<int>& nums){
        int n=nums.size();
        vector<int> st(n);
        vector<int> ed(n);
        ed[0]=1;
        ed[1]=2;
        int cr=nums[1]-nums[0];
        int cnt=2;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==cr){
                cnt++;
                ed[i]=cnt;
            }
            else{
                ed[i]=2;
                cnt=2;
                cr=nums[i]-nums[i-1];
            }
        }
        st[n-1]=1;
        st[n-2]=2;
        int cr2=nums[n-2]-nums[n-1];
        int cnt2=2;
        for(int i=n-3;i>=0;i--){
            if(nums[i]-nums[i+1]==cr2){
                cnt2++;
                st[i]=cnt2;
            }
            else{
                st[i]=2;
                cnt2=2;
                cr2=nums[i]-nums[i+1];
            }
        }
        int ans=2;
        for(int i=1;i<n-1;i++){
            int ol=ed[i-1]+1;
            int ox=st[i+1]+1;
            ans=max(ans,max(ol,ox));
            int d=(nums[i+1]-nums[i-1]);
            if(d%2!=0){continue;}
            d/=2;
            int leftd=1e6,rightd=1e6;
            if(i>=2){leftd=(nums[i-1]-nums[i-2]);}
            if(i<=n-3){
                rightd=nums[i+2]-nums[i+1];
            }
            if(leftd==d&&rightd==d){ans=max(ans,ed[i-1]+st[i+1]+1);}
            if(leftd==d){ans=max(ans,ed[i-1]+2);}
            if(rightd==d){ans=max(ans,st[i+1]+2);}
        }
        ans=max(ans,st[1]+1);
        ans=max(ans,ed[n-2]+1);
        return ans;
    }
};