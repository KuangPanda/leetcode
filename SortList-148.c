/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* combine(struct ListNode* low, struct ListNode* high) {
    struct ListNode* start = NULL;
    struct ListNode* temp = NULL;
    
    if (low == NULL && high == NULL) {
        return NULL;
    }
    if (low == NULL && high != NULL) {
        return high;
    }
    if (low != NULL && high == NULL) {
        return low;
    }
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    start = temp;
    
    while(NULL != low && NULL != high) {
        if(low -> val < high -> val) {
            temp -> next = low;
            low = low -> next;
        } else {
            temp -> next = high;
            high = high -> next;
        }
        temp = temp -> next;
    }
    
    if (low != NULL) {
        temp -> next = low;
    }
    
    if (high != NULL) {
        temp -> next = high;
    }
    
    return start -> next;
}

struct ListNode* findMid(struct ListNode* head) {
    struct ListNode* temp = NULL;
    struct ListNode* temp1 = NULL;
    struct ListNode* temp2 = NULL;
    
    if (NULL == head) {
        return head;
    }
    else {
        temp = head;
        temp1 = head;
        while(temp1 != NULL && temp1 -> next != NULL) {
            temp = temp -> next;
            temp1 = temp1 -> next -> next;
        }
        return temp;
    }
}

struct ListNode* findEnd(struct ListNode* head, struct ListNode* mid) {
    struct ListNode* temp = NULL;
    if (NULL == head || NULL == head -> next) {
        return head;
    } else {
        temp = head;
        while (temp != NULL && temp -> next != mid) {
            temp = temp -> next;
        }
        return temp;
    }
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* mid = NULL;
    struct ListNode* end = NULL;
    struct ListNode* tmpHead = NULL;
    struct ListNode* tmpLeft = NULL;
    struct ListNode* tmpRight = NULL;
    
    
    if (NULL == head) {
        return head;
    }
    
    mid = findMid(head);
    if (head == mid) {
        return head;
    }
    end = findEnd(head, mid);
    
    if(end != NULL) {
        end -> next = NULL;
    } else {
        return head;
    }
    
    tmpLeft = sortList(head);
    tmpRight = sortList(mid);
    
    tmpHead = combine(tmpLeft, tmpRight);
    return tmpHead;
}