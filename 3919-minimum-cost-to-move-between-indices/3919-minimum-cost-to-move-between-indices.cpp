typedef long long ll;
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        
        // prefRight[i] stores minimum cost to travel from index 0 to index i
        vector<long long> prefRight(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            long long cost;
            // Check if moving from i to i+1 is a "closest" move
            // For index 0, the only neighbor is 1, so 0 -> 1 is always cost 1
            if (i == 0) {
                cost = 1;
            } else {
                long long dist_left = (long long)nums[i] - nums[i - 1];
                long long dist_right = (long long)nums[i + 1] - nums[i];
                // Closest move if dist to right is strictly smaller than dist to left
                cost = (dist_right < dist_left) ? 1 : dist_right;
            }
            prefRight[i + 1] = prefRight[i] + cost;
        }

        // prefLeft[i] stores minimum cost to travel from index n-1 down to index i
        vector<long long> prefLeft(n, 0);
        for (int i = n - 1; i > 0; --i) {
            long long cost;
            // Check if moving from i to i-1 is a "closest" move
            if (i == n - 1) {
                cost = 1;
            } else {
                long long dist_left = (long long)nums[i] - nums[i - 1];
                long long dist_right = (long long)nums[i + 1] - nums[i];
                // Closest move if dist to left is <= dist to right (smaller index tie-break)
                cost = (dist_left <= dist_right) ? 1 : dist_left;
            }
            prefLeft[i - 1] = prefLeft[i] + cost;
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u <= v) {
                // Moving forward in the array
                ans.push_back(prefRight[v] - prefRight[u]);
            } else {
                // Moving backward in the array
                ans.push_back(prefLeft[v] - prefLeft[u]);
            }
        }
        
        return ans;
    }
};