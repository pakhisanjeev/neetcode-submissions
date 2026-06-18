class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (A.size() > B.size()) swap(A, B);

        int m = A.size(), n = B.size();
        int lo = 0, hi = m;
        int half = (m + n + 1) / 2;   // size of the left half

        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // partition index in A
            int j = half - i;           // partition index in B

            // Elements just left/right of each partition
            // Use INT_MIN/INT_MAX as sentinels for out-of-bounds
            int A_left  = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];
            int B_left  = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];

            if (A_left <= B_right && B_left <= A_right) {
                // ✅ Valid partition found
                int maxLeft  = max(A_left, B_left);
                int minRight = min(A_right, B_right);

                if ((m + n) % 2 == 1)
                    return maxLeft;           // odd total
                else
                    return (maxLeft + minRight) / 2.0; // even total

            } else if (A_left > B_right) {
                hi = i - 1;  // A's left side too big → move left
            } else {
                lo = i + 1;  // B's left side too big → move right
            }
        }

        return -1; // unreachable given valid input
    }
};
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> merged;

//         // Step 1: Dono arrays merge karo
//         for (int x : nums1) merged.push_back(x);
//         for (int x : nums2) merged.push_back(x);

//         // Step 2: Sort karo
//         sort(merged.begin(), merged.end());

//         int n = merged.size();

//         // Step 3: Median nikalo
//         if (n % 2 == 1) {
//             return merged[n / 2];           // odd → middle element
//         } else {
//             return (merged[n/2 - 1] + merged[n/2]) / 2.0;  // even → average of two middle
//         }
//     }
// };
