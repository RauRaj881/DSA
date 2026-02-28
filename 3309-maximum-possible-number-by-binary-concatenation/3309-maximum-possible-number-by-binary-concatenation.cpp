class Solution {
public:
int clc(int a,int b,int c){
    int szb=0,szc=0;
    int orib=b,oric=c;
    while(b!=0){
        szb++;
        b/=2;
    }
    while(c!=0){
        szc++;
        c/=2;
    }
    a<<=szb;
    a|=orib;
    a<<=szc;
    a|=oric;
    return a;
}
    int maxGoodNumber(vector<int>& nums) {
        int a=nums[0],b=nums[1],c=nums[2];
        int d=clc(a,b,c);
        int e=clc(a,c,b);
        int f=clc(b,a,c);
        int g=clc(b,c,a);
        int h=clc(c,a,b);
        int i=clc(c,b,a);
        return max(d,max(e,max(f,max(g,max(h,i)))));
    }
};