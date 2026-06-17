class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // stores: {number, index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If the complement exists in the map, we found our pair!
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            
            // Otherwise, keep track of the current number and its index
            num_map[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};