class Solution {
public:
    int smallestNumber(int n) {
        int x=(int)log2(n);
        return pow(2,x+1)-1;
    }
};