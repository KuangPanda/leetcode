/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
int getLength(struct ListNode* l) {
    struct ListNode* temp = NULL;
    int len = 0;
    
    if (NULL == l) {
        return 0;
    } else {
        temp = l;
        while(temp!= NULL) {
            len++;
            temp = temp -> next;
        }
        return len;
    }
}

struct ListNode* getNode(struct ListNode* l, struct ListNode* node) {
    struct ListNode* p = NULL;
    p = l;
    
    if (p == node) {
        return p;
    } else {
        while (p -> next != NULL) {
            if (p -> next == node) {
                return p;
            } 
            p = p -> next;
        }
    }
    return p;
}
    
struct ListNode* judge(struct ListNode* head, struct ListNode* index) {
    struct ListNode* temp = NULL;
    int num = 0;
    
    if (head == index) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp -> val = 1;
        temp -> next = head;
        return temp;
    } else {
        temp = getNode(head, index);
        num = temp -> val + 1;
        if (num < 10) {
            temp -> val += 1;
            return head;
        } else {
            temp -> val = 0;
            head = judge(head, temp);
        }
    }
    return head;
}    
    
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = 0;
    int len2 = 0;
    int index = 0;
    int distance = 0;
    
    struct ListNode* temp1 = NULL;
    struct ListNode* temp2 = NULL;
    
    

    if (!l1 && !l2) {
        return NULL;
    } else if (!l1 && l2) {
        return l2;
    } else if (!l2 && l1) {
        return l1;
    } else {
        len1 = getLength(l1);
        len2 = getLength(l2);
        
        if (len1 == len2) {
            temp1 = l1;
            temp2 = l2;
            while(temp2 != NULL) {
                temp1 -> val = temp1 -> val + temp2 -> val;
                if (temp1 -> val >= 10) {
                    temp1 -> val -= 10;
                    l1 = judge(l1, temp1);
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l1;
        } else if (len1 > len2) {
            index = 0;
            distance = len1 - len2;
            temp1 = l1;
            temp2 = l2;
            while(temp1 != NULL) { 
                if (index == distance) {
                    break;
                } else {
                    temp1 = temp1 -> next;
                }
                index ++;
            }
            
            while(temp2 != NULL) {
                temp1 -> val = temp1 -> val + temp2 -> val;
                if (temp1 -> val >= 10) {
                    temp1 -> val -= 10;
                    l1 = judge(l1, temp1);
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l1;
        } else {
            index = 0;
            distance = len2 - len1;
            temp1 = l1;
            temp2 = l2;
            while(temp2 != NULL) {
                if (index == distance) {
                    break;
                } else {
                    temp2 = temp2 -> next;
                }
                index ++;
            }

            while(temp1 != NULL) {
                temp2 -> val = temp1 -> val + temp2 -> val;
                if (temp2 -> val >= 10) {
                    temp2 -> val -= 10;
                    l2 = judge(l2, temp2);
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l2;
        }
    }
}
