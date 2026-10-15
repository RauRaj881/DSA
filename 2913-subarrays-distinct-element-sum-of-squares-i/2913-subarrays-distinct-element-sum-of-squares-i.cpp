class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();                                   // Store the size of the array
        long long ans = 0;                                     // Final answer in long long
        
        for (int i = 0; i < n; i++) {                          // Fix the starting index
            unordered_map<int, int> freq;                      // Frequency map for current subarray
            int distinct = 0;                                  // Count of distinct elements in current subarray
            
            for (int j = i; j < n; j++) {                      // Expand the subarray to the right
                if (freq[nums[j]] == 0) {                      // If this number is seen for the first time
                    distinct++;                                // Increase distinct count
                }
                freq[nums[j]]++;                               // Update frequency of current number
                ans += 1LL * distinct * distinct;              // Add square of distinct count
            }
        }
        
        return (int)ans; 

        
    }
};