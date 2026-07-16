class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
        int n=nums.size();
        vector<double> ans;
        auto cmp = [&](int a, int b) {
            if (nums[a] == nums[b]) return a < b;
            return nums[a] < nums[b];
        };

        multiset<int, decltype(cmp)> ms1(cmp), ms2(cmp);
        for(int i=0;i<n;i++){
            if(i>=k){if(ms1.count(i-k)){ms1.erase(i-k);}else{ms2.erase(i-k);}}
            if(ms1.empty()||nums[i]<nums[*ms1.rbegin()]){
                ms1.insert(i);
            }
            else{
                ms2.insert(i);
            }
            if(ms1.size()>ms2.size()+1){
                ms2.insert(*ms1.rbegin());
                ms1.erase(*ms1.rbegin());
            }
            else if(ms2.size()>ms1.size()){
                ms1.insert(*ms2.begin());
                ms2.erase(*ms2.begin());
            }
            if(i>=k-1){
                double tp;
                if(ms1.size()>ms2.size()){
                    tp=nums[*ms1.rbegin()];
                }
                else{
                    tp = ((long long)nums[*ms1.rbegin()] + (long long)nums[*ms2.begin()]) / 2.0;
                }
                ans.push_back(tp);
            }
        }
        return ans;
    }
};