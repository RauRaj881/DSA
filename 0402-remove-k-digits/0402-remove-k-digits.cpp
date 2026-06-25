class Solution {
public:
    string removeKdigits(string nums, int k){
        string st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&st.back()>nums[i]&&k>0){
                st.pop_back();
                k--;
            }
            st+=nums[i];
        }
        while(k>0){st.pop_back();k--;}
        int i=0;
        while(i<st.size()&&st[i]=='0'){i++;}
        if(i==st.size()||st.size()==0){return "0";}
        return st.substr(i,st.size()-i);
    }
};