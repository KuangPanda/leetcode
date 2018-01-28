// Here is mine
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* l) {
        if (NULL == l) {
            return 0;
        }
        
        int length = 1;
        ListNode *temp = l -> next;
        while (temp != NULL) {
            length++;
            temp = temp -> next;
        }
        return length;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            int length1 = getLength(l1);
            int length2 = getLength(l2);
    
            if (length1 >= length2) {
                ListNode* temp = l1;
                while(temp != NULL && l2 != NULL) {
                    temp -> val = temp -> val + l2 -> val;
                    if (temp -> next != NULL && temp -> val > 9) {
                        temp -> next -> val += 1;
                    } else if (temp -> next == NULL && temp -> val > 9) {
                        temp -> next = new ListNode(0);
                        temp -> next -> val = 1;
                        temp -> next -> next = NULL;
                    }
                    temp -> val %= 10;
                    temp = temp -> next;
                    l2 = l2 -> next;
                }
                
                while (temp != NULL && temp -> val > 9) {
                    temp -> val = temp -> val % 10;
                    if (temp -> next == NULL) {
                        temp -> next = new ListNode(0);
                    }
                    temp -> next -> val += 1;
                    temp = temp -> next;
                }
                
                return l1;
            } else {
                ListNode* temp = l2;
                while (temp != NULL && l1 != NULL) {
                    temp -> val = temp -> val + l1 -> val;
                    if (temp -> next != NULL && temp -> val > 9) {
                        temp -> next -> val += 1;
                    } else if (temp -> next == NULL && temp -> val > 9) {
                        temp -> next = new ListNode(0);
                        temp -> next -> val = 1;
                        temp -> next -> next = NULL;
                    }
                    
                    temp -> val %= 10;
                    temp = temp -> next;
                    l1 = l1 -> next;
                }
                
                while (temp != NULL && temp -> val > 9) {
                    temp -> val = temp -> val % 10;
                    if (temp -> next == NULL) {
                        temp -> next = new ListNode(0);
                    }
                    temp -> next -> val += 1;
                    temp = temp -> next;
                }
                
                return l2;
            }
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