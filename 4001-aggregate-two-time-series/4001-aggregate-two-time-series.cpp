class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2){
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<s1.size()&&j<s2.size()){
            if(s1[i][0]==s2[j][0]){
                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;j++;
            }
            else if(s1[i][0]<s2[j][0]){
                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;
            }
            else{
                ans.push_back({s2[j][0],s1[i][1]+s2[j][1]});
                j++;
            }
        }
        while(i<s1.size()){ans.push_back({s1[i][0],s1[i][1]});i++;}
        while(j<s2.size()){ans.push_back({s2[j][0],s2[j][1]});j++;}
    return ans;
    }
};