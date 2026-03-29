class Solution {
public:
    bool isSortable(const vector<int>& nums, const vector<int>& target, int k, int n) {
    for (int i = 0; i < n; i += k) {
        // 1. Extract the current k-length block
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);
        
        // 2. Extract what the sorted version of THIS block SHOULD be
        vector<int> expected(target.begin() + i, target.begin() + i + k);
        
        // 3. Check if 'sub' contains the correct elements
        vector<int> temp = sub;
        sort(temp.begin(), temp.end());
        if (temp != expected) return false;

        // 4. Check if 'sub' is a cyclic rotation of 'expected'
        // A cyclic rotation of a sorted array has at most one "drop"
        int drops = 0;
        for (int j = 0; j < k; ++j) {
            if (sub[j] > sub[(j + 1) % k]) {
                drops++;
            }
        }
        
        // A perfectly sorted block (all same) has 0 drops.
        // A rotated sorted block has exactly 1 drop.
        if (drops > 1) return false;
    }
    return true;
}
    int sortableIntegers(vector<int>& nums){
        vector<int> qelvarodin = nums;
        int n = qelvarodin.size();
        
        vector<int> target = qelvarodin;
        sort(target.begin(), target.end());

        long long totalSum = 0;
        
        // Find all divisors of n
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(qelvarodin, target, k, n)) {
                    totalSum += k;
                }
            }
        }
        
        return totalSum;
        
    }
};