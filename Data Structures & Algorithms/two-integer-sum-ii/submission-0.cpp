class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> ans(2);
        while(i<j){
        if(numbers[i]+numbers[j]==target){
        ans[0]=i+1;
        ans[1]=j+1;
        return ans;
        }
        else if(numbers[i]+numbers[j]>target){
        j--;
        }
        else i++;
   
        }
        return {};
    }
};
