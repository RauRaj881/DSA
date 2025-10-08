class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        queue<vector<int>> q;
        q.push(nums1);
        set<vector<int>> s;
        s.insert(nums1);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            vector<int> temp1=q.front();
            q.pop();
            if(temp1==nums2){return level;}
            for(int l=0;l<n;l++){
                for(int r=l;r<n;r++){
                    vector<int> temp=temp1;
                    vector<int> cut(temp.begin()+l,temp.begin()+r+1);
                    temp.erase(temp.begin()+l,temp.begin()+r+1);
                    vector<int> rem=temp; 
                    int remsize=rem.size();
                    for(int i=0;i<remsize;i++){
                        vector<int> curr=temp;
                        curr.insert(curr.begin()+i,cut.begin(),cut.end());
                        if(s.find(curr)==s.end()){
                            s.insert(curr);
                            q.push(curr);
                        }
                    }
                }
            }
            }
            level++;
        }
        return 0;
    }
};
//yaha pe 1 bar substring cut + merge matlab agle level pe chale gaye.