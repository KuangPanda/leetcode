class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator last = digits.end() - 1;
        *last += 1;
        while(last != digits.begin()) {
            if(*last > 9) {
                *last = *last - 10;
                *(last - 1) += 1;
            }
            last -= 1;
        }

        if(*(digits.begin()) > 9) {
            digits.push_back(0);
            digits[0] = 0;
            for (int i = digits.size() - 1; i > 0; i--) {
                digits[i] = digits[i - 1];
            }
            digits[0] = 1;        
        }
        return digits;
    }
};