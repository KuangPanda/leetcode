/**
 * 2. https://leetcode.com/problems/add-two-numbers/description/ 
 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 **/


#include<iostream>
#include<cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        
        if(!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else if(len1 >= len2) {
            while(temp2) {
                temp1 -> val = temp1 -> val + temp2 -> val;
            
                if(temp1 -> val >= 10) {
                    temp1 -> val %= 10;
                    
                    if(!temp1 -> next) {
                        temp1 -> next = (ListNode*)malloc(sizeof(ListNode));
                        temp1 -> next -> val = 1;
                        temp1 -> next -> next = NULL;
                    } else {
                        temp1 -> next -> val += 1;
                        changeTen(temp1 -> next);
                    }
                }
            
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l1;
        } else {
            while(temp1) {
                temp2 -> val = temp2 -> val + temp1 -> val;
                
                if(temp2 -> val >= 10) {
                    temp2 -> val %= 10;
                    
                    if(!temp2 -> next) {
                        temp2 -> next = (ListNode*)malloc(sizeof(ListNode));
                        temp2 -> next -> val = 1;
                        temp2 -> next -> next = NULL;
                    } else {
                        temp2 -> next -> val += 1;
                        changeTen(temp2 -> next);
                    }
                }
                
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l2;
        }
    }
    
    int getLength(ListNode *l) {
        int count = 0;
        ListNode* temp = l;
        
        while(temp) {
            count ++;
            temp = temp -> next;
        }
        
        return count;
    }
    
    void changeTen(ListNode *l) {
        ListNode *temp = l;
        while(temp -> val == 10) {
            temp -> val %= 10;
            if(temp -> next) {
                temp -> next -> val += 1;
            } else {
                temp -> next = (ListNode*)malloc(sizeof(ListNode));
                temp -> next -> val = 1;
                temp -> next -> next = NULL; 
            }
            
            temp = temp -> next;
        }
    }
};

// Here is others
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        int carry = 0;
        
        while(l1 || l2) {
            
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            
            int sum = a + b + carry;
            carry = sum / 10;
            
            cur = cur->next = new ListNode(sum % 10);
            
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        
        if(carry) {
            cur->next = new ListNode(1);
        }
        
        return dummy.next;
    }
};
