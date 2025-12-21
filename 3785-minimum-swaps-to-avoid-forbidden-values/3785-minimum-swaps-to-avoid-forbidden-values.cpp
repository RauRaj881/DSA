class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forb) {
        int n=nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto it:nums){
            mp1[it]++;
        }
        for(auto it:forb){
            mp2[it]++;
        }
        for(auto it:forb){
            if(mp1[it]>n-mp2[it]){
                return -1;
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==forb[i]){
                mp[nums[i]]++;
            }
        }
        int cnt=0;
        for(auto &it:mp){
            if(it.second==1){cnt++;it.second=0;}
        }
        int x=cnt;
        int ans=0;
        for(auto &it:mp){
            if(it.second>1){
            if(it.second>=cnt){it.second-=cnt;cnt=0;break;}
            else{
                cnt-=it.second;
                it.second=0;
            }
            }
        }
        if(cnt>0&&cnt%2==0&&cnt==x){return cnt/2;}
        if(cnt>0&&cnt%2==1&&cnt==x){return (cnt/2+1);}
        else if(cnt!=x){ans+=x-cnt;}
        if(cnt%2==0&&cnt>0){ans+=cnt/2;}
        else if(cnt%2==1&&cnt>0){ans+=cnt/2+1;}
        int y=0,uh=0;
        for(auto &it:mp){
            if(it.second>0){
                y+=it.second;uh++;
            }
        }
        if(uh==1){ans+= y;}
        else if(y>0&&y%2==0){ans+=y/2;}
        else if(y>0&&y%2==1){ans+=y/2+1;}
        return ans;
    }
};