class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        // Step 1: Dono arrays merge karo
        for (int x : nums1) merged.push_back(x);
        for (int x : nums2) merged.push_back(x);

        // Step 2: Sort karo
        sort(merged.begin(), merged.end());

        int n = merged.size();

        // Step 3: Median nikalo
        if (n % 2 == 1) {
            return merged[n / 2];           // odd → middle element
        } else {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;  // even → average of two middle
        }
    }
};
