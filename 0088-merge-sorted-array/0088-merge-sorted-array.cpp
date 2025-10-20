/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};*/
// forward se nums1 me overwrite jisse wrong answers isiliye backward se karenge
// WRONG
/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=0,i2=0,i=0;
        while(i1<m&&i2<n){
            if(nums1[i1]<nums2[i2]){
                nums1[i]=nums1[i1];
                i1++;
            }
            else{ 
                nums1[i]=nums2[i2];
                i2++;
                }
                i++;
        }
        while(i2<n){
            nums1[i]=nums2[i2];
            i2++;
            i++;
        }
    }
};*/
//CORRECT(from backward)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=m-1,i2=n-1,i=m+n-1;
        while(i1>=0&&i2>=0){
            if(nums1[i1]>nums2[i2]){
                nums1[i]=nums1[i1];
                i1--;
            }
            else{
                nums1[i]=nums2[i2];
                i2--;
            }
            i--;
        }
        while(i2>=0){
            nums1[i]=nums2[i2];
            i2--;i--;
        }
    }
};