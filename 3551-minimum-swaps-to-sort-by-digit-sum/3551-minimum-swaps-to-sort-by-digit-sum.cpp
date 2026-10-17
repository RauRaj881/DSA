class Solution{
public:
static bool cmp(int a,int b){
    int sm1=0,sm2=0;
    int num1=a,num2=b;
    while(num1>0){
        sm1+=num1%10;
        num1/=10;
    }
    while(num2>0){
        sm2+=num2%10;
        num2/=10;
    }
    if(sm1==sm2){return a<b;}
    return sm1<sm2;
}
    int minSwaps(vector<int>& nums){
        int n=nums.size();
        vector<int> aftersorted=nums;
        sort(aftersorted.begin(),aftersorted.end(),cmp);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int cr=nums[i];
            int exp=aftersorted[i];
            if(cr==exp){continue;}
            int idx=mp[exp];
            mp[cr]=idx;
            mp[exp]=i;
            //nums[i]=exp;
            nums[idx]=cr;
            ans++;
        }
        return ans;
    }
};