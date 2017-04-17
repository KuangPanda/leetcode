/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* insertList(struct ListNode* head, struct ListNode* node) {
    struct ListNode* temp = NULL;
    
    if (NULL == head) {
        return NULL;
    }
    
    if (head -> val > node -> val) {
        node -> next = head;
        head = node;
        return head;
        //printf("%d\n", head -> next -> val);
        //return 0;
    }
    
    temp = head;
    if(temp -> next == NULL) {
        temp -> next = node;
        node -> next = NULL;
        return head;
        //return 0;
    } else {
        while(temp -> next != NULL) {
            if(node -> val >= temp -> val && node -> val < temp -> next -> val) {
                node -> next = temp -> next;
                temp -> next = node;
                return head;
                //return 0;
            }
            temp = temp -> next;
        }
        temp -> next = node;
        node -> next = NULL;
        return head;
        //return 0;
    }
}
 
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* temp = head;
    struct ListNode* begin = NULL;
    
    if (NULL == head || NULL == head -> next) {
        return head;
    }
    
    begin = head -> next;
    head -> next = NULL;
    
    while(begin != NULL) {
        temp = begin -> next;
        begin -> next = NULL;
        head = insertList(head, begin);
        //insertList(head, begin);
        begin = temp;
    }

    return head;
}