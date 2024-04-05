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
    bool hasCycle(ListNode *head) {
        if (NULL == head)
            return false;
        
        ListNode* fastPtr = head;
        while((head != NULL) && (fastPtr != NULL) && (fastPtr->next != NULL))
        {
            head = head->next;
            fastPtr = fastPtr->next->next;
            if (fastPtr == head)
                return true;
        }
        
        return false;
    }
};