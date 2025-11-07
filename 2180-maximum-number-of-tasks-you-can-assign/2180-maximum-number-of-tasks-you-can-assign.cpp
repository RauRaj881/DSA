class Solution {
public:
bool isPossible(int mid,vector<int>& tasks, vector<int>& workers, int pills, int strength){
    int n=tasks.size();
    int m=workers.size();
    int i=0;
    int cnt=0;
    multiset<int> ms;
    for(int i=m-mid;i<m;i++){ms.insert(workers[i]);}
    for(int i=mid-1;i>=0;i--){
        auto it1=ms.lower_bound(tasks[i]);
        auto it2=ms.lower_bound(tasks[i]-strength);
        if(it1!=ms.end()){
            ms.erase(it1);
        }
        else if(it2!=ms.end()&&pills>0){
            ms.erase(it2);
            pills--;
        }
        else{return false;}
    }
    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int low=0,high=min(n,m);
        int ans=0;
        while(low<=high){
            int mid=(high+low)/2;
            if(isPossible(mid,tasks,workers,pills,strength)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};