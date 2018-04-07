/**
 * 4. https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0

 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]

 * The median is (2 + 3)/2 = 2.5 
 **/

class Solution {
public:
    
    bool judgeOdd(int num) {
        if(num % 2) {
            return true;
        } else {
            return false;
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) {
            int len = nums2.size();
            if(judgeOdd(len)) {
                return nums2[len / 2];
            } else {
                return (double(nums2[len / 2]) + double(nums2[len / 2 - 1])) / 2;
            }
        } else if(nums2.size() == 0) {
            int len = nums1.size();
            if(judgeOdd(len)) {
                return nums1[len / 2];
            } else {
                return (double(nums1[len / 2]) + double(nums1[len / 2 - 1])) / 2;
            }
        } else {
            int sum = nums1.size() + nums2.size();
            
            vector<int> median;
        
            if(judgeOdd(sum)) {
                median.push_back(sum / 2);    
            } else {
                int temp = sum / 2;
                median.push_back(temp);
                median.push_back(temp - 1);
            }
            
            vector<int> result;
            int count = 0;
        
            int i = 0;
            int j = 0;
            
            while(count <= median[0] && i < nums1.size() && j < nums2.size()) {
                if(nums1[i] < nums2[j]) {
                    result.push_back(nums1[i]);
                    i++;
                } else {
                    result.push_back(nums2[j]);
                    j++;
                }
                count++;
            }
            
            while(count <= median[0]) {
                if(i >= nums1.size()) {
                    result.push_back(nums2[j]);
                    j++;
                } else {
                    result.push_back(nums1[i]);
                    i++;
                }
                count++;
            }

            for(int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            
            if(median.size() == 1) {
                return result[median.back()];
            } else {
                return ((double)result[median.back()] + double(result[median[0]])) / 2;
            }
        }
    }
};