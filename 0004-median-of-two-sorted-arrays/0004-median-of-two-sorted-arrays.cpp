class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums2.size() > nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;

        int low = max(0, total / 2 - n2);
        int high = min(n1, total / 2);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = total / 2 - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (left1 > right2) {
                high = cut1 - 1;
            }
            else if (left2 > right1) {
                low = cut1 + 1;
            }
            else {
                if (total % 2 == 1)
                    return min(right1, right2);

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
        }

        return 0.0;
    }
};