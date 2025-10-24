class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int up=0,down=0,peak=0;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                sum += 1 + up;                   
            } 
            else if (ratings[i] < ratings[i - 1]) {
                down++;
                up = 0;
                sum += 1 + down - (peak >= down ? 1 : 0);
            } 
            else {
                up = down = peak = 0;
                sum += 1;
            }
        }
        return sum;
    }
};
