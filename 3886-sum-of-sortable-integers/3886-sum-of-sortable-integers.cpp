class Solution {
public:
    bool isvalid(int k,vector<int>&nums,vector<int>&st){
        for(int i=0;i<nums.size();i+=k){
            int cnt=0;
            vector<int> tp(nums.begin()+i,nums.begin()+i+k);
            vector<int> ntp=tp;
            sort(ntp.begin(),ntp.end());
            vector<int> x(st.begin()+i,st.begin()+i+k);
            if(ntp!=x){return false;}
            for(int i=1;i<tp.size();i++){
                if(tp[i]<tp[i-1]){cnt++;}
            }
            if(cnt>1||(cnt==1&&tp[0]<tp[tp.size()-1])){return false;}
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums){
        int n=nums.size();
        vector<int> div;
        for(int i=1;i<=n;i++){
            if(n%i==0){div.push_back(i);}
        }
        vector<int> st=nums;
        sort(st.begin(),st.end());
        int ans=0;
        for(int i=0;i<div.size();i++){
            if(isvalid(div[i],nums,st)){ans+=div[i];}
        }
        return ans;
        
    }
};