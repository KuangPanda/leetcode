class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (temp == nums[j]) {
                    return vector<int>{i, j};
                }
            }
        }
    }
};