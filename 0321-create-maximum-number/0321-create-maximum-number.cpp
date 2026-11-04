class Solution {
public:
string f(vector<int>& nums1,int k){
    string s="";
    for(int i=0;i<nums1.size();i++){
        while(s.size()>0&&s.back()<nums1[i]+'0'&&k>0){
            s.pop_back();
            k--;
        }
        s.push_back(nums1[i]+'0');
    }
    while(k>0){
        s.pop_back();
        k--;
    }
    return s;
}
vector<int> merge(string& s1,string& s2){
    int n1=s1.size();
    int n2=s2.size();
    vector<int> curr;
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(s1.substr(i) > s2.substr(j)){
            curr.push_back(s1[i]-'0');
            i++;
        }
        else{
            curr.push_back(s2[j]-'0');
            j++;
        }
    }
    while(i<n1){
        curr.push_back(s1[i]-'0');
        i++;
    }
    while(j<n2){
        curr.push_back(s2[j]-'0');
        j++;
    }
    return curr;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans;
        for(int len1=0;len1<=min(m,k);len1++){
            int len2=k-len1;
            if(len2>n){continue;}
            string s1=f(nums1,m-len1);
            string s2=f(nums2,n-len2);
            vector<int> curr=merge(s1,s2);
            ans=max(ans,curr);
        }
        return ans;
    }
};