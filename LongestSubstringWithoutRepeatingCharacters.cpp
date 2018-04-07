/**
 * 3. https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 
 * Given a string, find the length of the longest substring without repeating characters.
 
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring
 **/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result   = 0;
        
        string temp;
        
        for(int j = 0; j < s.size(); j++) {
            temp.push_back(s[j]);
            
            for(int i = j + 1; i < s.size(); i++) {
                if(temp.find(s[i]) != temp.npos) {
                    break;
                } else {
                    temp.push_back(s[i]);
                }    
            }
            
            int length = temp.size();
            result = max(result, length);
            temp = string();
        }
        
        int length = temp.size();
        return max(result, length);
    }
};
