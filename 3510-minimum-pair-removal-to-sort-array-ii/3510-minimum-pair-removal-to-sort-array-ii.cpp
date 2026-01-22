class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> nxt(n);
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            a[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            pre[i]=i-1;
            nxt[i]=i+1;
        }
        set<pair<long long,int>> s;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                cnt++;
            }
            s.insert({a[i]+a[i+1],i});
        }
        while(cnt>0){
            auto it = s.begin();
            int i = it->second;
            int j=nxt[i];
            int p=pre[i];
            int q=nxt[j];
            s.erase(s.begin());
            if(a[i]>a[j])cnt--;
            long long sm=a[i]+a[j];
            if(p>=0){
            if(a[p]>a[i]&&sm>=a[p]){
                cnt--;
            }
            else if(a[p]<=a[i]&&sm<a[p]){
                cnt++;
            }
            }

            if(q<n){
                if(a[j]>a[q]&&sm<=a[q]){
                    cnt--;
                }
                else if(a[j]<=a[q]&&sm>a[q]){
                    cnt++;
                }
            }
            if(p>=0){
               s.erase({a[p]+a[i],p});
               s.insert({a[p]+sm,p});
            }
            if(q<n){
                s.erase({a[j]+a[q],j});
                s.insert({sm+a[q],i});
                pre[q]=i;
            }
            a[i]=a[i]+a[j];
            nxt[i]=q;
            ans++;
        }  
        return ans;
    }
};