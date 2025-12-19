class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        if(n==0){return {};}
        s.insert(nums[0]);
        vector<string> ans;
        for(int i=1;i<n;i++){
            if(nums[i]-1==nums[i-1]){
                s.insert(nums[i]);
            }
            else{
                if(s.size()==1){int a=*(s.begin());string x=to_string(a);ans.push_back(x);}
                else{int a=*(s.begin());int b=*(s.rbegin());
                string x=to_string(a);string y=to_string(b);
                string z=x+"-"+">"+y;
                ans.push_back(z);}
                s.clear();
                s.insert(nums[i]);
            }
        }

        if(s.size()==1){int a=*(s.begin());string x=to_string(a);ans.push_back(x);}
        else{
            int a=*(s.begin());int b=*(s.rbegin());
            string x=to_string(a);string y=to_string(b);
            string z=x+"-"+">"+y;
            ans.push_back(z);}
            return ans;
    }
};