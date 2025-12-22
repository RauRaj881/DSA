class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int l=points[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            int mn=points[i][0];
            int mx=points[i][1];
            if(mn<=l){
                l=min(mx,l);
            }
            else{
                cnt++;
                l=points[i][1];
            }
        }
        return cnt+1;
    }
};