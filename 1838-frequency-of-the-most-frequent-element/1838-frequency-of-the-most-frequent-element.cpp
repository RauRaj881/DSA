/*class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int i=1;i<n;i++){
            int p=nums[i]-nums[i-1];
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        int sum=0,t=1;
        for(int j=0;j<n-1;j++){
            if(sum+v[j]<=k){sum+=v[j];t++;}
            else break;
        }
        return t;
    }
};*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k) {
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long l=0,r=0;
        vector<long long> sumtill(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sumtill[i]=sum;
        }
        long long ans=1;
        while(r<n){
            long long winsize=r-l+1;
            long long st=(winsize*nums[r]-(sumtill[r]-(l>0?sumtill[l-1]:0)));
            if(st<=k){
                ans=max(ans,r-l+1);
                r++;
            }
            else{l++;}
        }
        return ans;
    }
};