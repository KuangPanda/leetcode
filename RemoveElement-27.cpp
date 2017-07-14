class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int>::iterator it;
        while ((it=find(nums.begin(), nums.end(), val)) != nums.end()) {
            nums.erase(it);
        }
        
        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;

        if (nums.size() == 0) {
            return 0;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }

        return count;
    }
};