class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int left1 = (partition1 == 0)
                        ? INT_MIN
                        : nums1[partition1 - 1];

            int right1 = (partition1 == m)
                         ? INT_MAX
                         : nums1[partition1];

            int left2 = (partition2 == 0)
                        ? INT_MIN
                        : nums2[partition2 - 1];

            int right2 = (partition2 == n)
                         ? INT_MAX
                         : nums2[partition2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd number of elements
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even number of elements
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // Move partition1 to the left
            if (left1 > right2) {
                high = partition1 - 1;
            }
            // Move partition1 to the right
            else {
                low = partition1 + 1;
            }
        }

        return 0.0;
    }
};