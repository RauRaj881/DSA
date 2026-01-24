class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(k==n){return arr;}
        vector<int> ans;
        auto it=lower_bound(arr.begin(),arr.end(),x);
        if(it==arr.end()){
            int i=n-1;
            while(k--){
                ans.push_back(arr[i]);
                i--;
            }
        }
        else if(it==arr.begin()){
            int i=0;
            while(k--){
                ans.push_back(arr[i]);
                i++;
            }
        }
        else{
            int idx=it-arr.begin();
            int i=idx-1,j=idx;
            while(k>0&&i>=0&&j<n){
                if(abs(arr[i]-x)<=abs(arr[j]-x)){
                    ans.push_back(arr[i]);
                    i--;
                }
                else{
                    ans.push_back(arr[j]);
                    j++;
                }
                k--;
            }
            if(k>0){
                if(i<0){
                    while(k>0){
                        ans.push_back(arr[j]);j++;k--;
                    }
                }
                else{
                    while(k>0){
                        ans.push_back(arr[i]);i--;k--;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};