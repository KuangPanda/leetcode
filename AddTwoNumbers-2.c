/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
int getLength(struct ListNode* l) {
    int len = 0;
    struct ListNode* temp = NULL;
    if(l == NULL) {
        return 0;
    } else {
        temp = l;
        while(temp != NULL) {
            len ++;
            temp = temp -> next;
        }
        return len;
    }
}

struct ListNode* judge(struct ListNode* head) {
    int temp = 0;
    struct ListNode* p = NULL;

    if(head == NULL) {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p -> val = 1;
        p -> next = NULL;
        return p;
    } else {
        temp = head -> val + 1;
        if (temp < 10) {
            head -> val += 1;
            return head;
        } else {
            p = head;
            p -> val = 0;
            p -> next = judge(p -> next); 
        }
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = 0;
    int len2 = 0;
    int num = 0;
    struct ListNode* temp1 = NULL;
    struct ListNode* temp2 = NULL;

    if (l1 == NULL && l2 == NULL) {
        return NULL;
    } else if (l1 != NULL && l2 == NULL) {
        return l1;
    } else if (l1 == NULL && l2 != NULL) {
        return l2;
    } else {
        len1 = getLength(l1);
        len2 = getLength(l2);

        temp1 = l1;
        temp2 = l2;

        if (len1 >= len2) {
            while (temp2 != NULL) {
                num = temp1 -> val + temp2 -> val;
                if (num < 10) {
                    temp1 -> val = num;
                } else {
                    temp1 -> val = num - 10;
                    temp1 -> next = judge(temp1 -> next);
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l1;
        } else {
            while (temp1 != NULL) {
                num = temp1 -> val + temp2 -> val;
                if (num < 10) {
                    temp2 -> val = num;
                } else {
                    temp2 -> val = num - 10;
                    temp2 -> next = judge(temp2 -> next);
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            return l2;
        }
    }
}