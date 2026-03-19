class Solution {
public:
int fup(int a,vector<int> &parent){
    if(parent[a]==a){return a;}
    return fup(parent[a],parent);
}
void union_by_rank(int a,int b,vector<int> &parent,vector<int> &rank){
    int ulp_a=fup(a,parent);
    int ulp_b=fup(b,parent);
    if(ulp_a!=ulp_b){
        if(rank[ulp_a]>rank[ulp_b]){
            parent[ulp_b]=ulp_a;
        }
        else if(rank[ulp_a]<rank[ulp_b]){
            parent[ulp_a]=ulp_b;
        }
        else{
            parent[ulp_b]=ulp_a;
            rank[ulp_a]++;
        }
    }
}
    int maxActivated(vector<vector<int>>& pts){
        int p=pts.size();
        unordered_map<int,int> ux;
        unordered_map<int,int> uy;
        vector<int> parent(p);
        vector<int> rank(p);
        for(int i=0;i<p;i++){parent[i]=i;}
        for(int i=0;i<p;i++){rank[i]=1;}
        for(int i=0;i<pts.size();i++){
            int x=pts[i][0];
            int y=pts[i][1];
            if(ux.count(x)){union_by_rank(i,ux[x],parent,rank);}
            else{ux[x]=i;}
            if(uy.count(y)){union_by_rank(i,uy[y],parent,rank);}
            else{uy[y]=i;}
        }
        unordered_map<int,int> comp;
        for(int i=0;i<p;i++){
            comp[parent[i]]++;
        }
        if(comp.size()==1){return p+1;}
        int mx1=0,mx2=0;
        for(auto it:comp){
            int att=it.second;
            if(att>mx1){
                mx2=mx1;
                mx1=att;
            }
            else if(att>mx2){
                mx2=att;
            }
        }
        return mx1+mx2+1;
    }
};