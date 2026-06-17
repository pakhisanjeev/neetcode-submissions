class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<(int)nums.size()-1;i++){
        // if(nums[i]==nums[i+1]) return true;
        // }
        // return false;
        unordered_set<int>seen;
        for(int n : nums){
        if(seen.count(n)) return true;
        seen.insert(n);
        } return  false;
    }
};