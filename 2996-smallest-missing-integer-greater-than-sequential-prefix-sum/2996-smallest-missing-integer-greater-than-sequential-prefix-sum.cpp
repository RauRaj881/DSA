class Solution {
public:
    int missingInteger(vector<int>& nums){
        int n=nums.size();
        int sm=nums[0];bool pos=true;
        unordered_set<int> st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1&&pos){sm+=nums[i];st.insert(nums[i]);}
            else{pos=false;st.insert(nums[i]);}
        }
        if(sm>50){return sm;}
        for(int i=sm;i<=51;i++){
            if(!st.count(i)){return i;}
        }
        return -1;
    }
};