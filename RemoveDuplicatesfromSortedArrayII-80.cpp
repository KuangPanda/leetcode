class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] != nums[j]) {
                    break;
                } else {
                    int count = 1;
                    while(nums[j] == nums[j + count] && j + 1 < nums.size()) {
                        nums.erase(nums.begin() + j, nums.begin() + j + count);
                    }
                }
            }
        }
        
        return nums.size();
        
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int j = 0;
        int num = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[j]) {
                num++;
                if (num < 2) {
                    nums[++j] = nums[i];
                }
            } else {
                nums[++j] = nums[i];
                num = 0;
            }    
        }
        return j + 1;
    }
};