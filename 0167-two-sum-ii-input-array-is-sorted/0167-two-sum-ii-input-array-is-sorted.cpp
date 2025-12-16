class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        int i=0,j=n-1;
        while(i<=j){
            if(num[i]+num[j]>target){j--;}
            else if(num[i]+num[j]<target){i++;}
            else{return {i+1,j+1};}
        }
        return {};
        
    }
};