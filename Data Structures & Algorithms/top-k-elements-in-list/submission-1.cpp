class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int n : nums) freq[n]++;

        vector<int> result;
        while (k--) {
            int maxFreq = 0, maxNum = 0;
            for (auto& [num, count] : freq) {
                if (count > maxFreq) {
                    maxFreq = count;
                    maxNum = num;
                }
            }
            result.push_back(maxNum);
            freq.erase(maxNum);
        }
        return result;
    }
};