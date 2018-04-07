class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator start = nums.begin();
        vector<int>::iterator temp;
        while(start != nums.end()) {
            temp = start + 1;
            while (temp != nums.end()) {
                if (*start == *temp) {
                    temp = nums.erase(temp);
                } else {
                    break;
                }
            }
            start++;
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
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        
        return j + 1;
    }
};