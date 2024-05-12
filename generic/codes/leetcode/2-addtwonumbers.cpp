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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* lresult = NULL;
        ListNode* presult = lresult;
        
        int carry = 0;
        while( (l1 != NULL) && l2 != NULL)
        {
            int sum = carry + l1->val + l2->val;
            carry = (sum >= 10) ? 1 : 0;
            sum %= 10;

            lresult = new ListNode(sum);
            
            if (result == NULL)
                result = lresult;
            else
                presult->next = lresult;
            presult = lresult;

            l1 = l1->next;
            l2 = l2->next;
        }
        
        l1 = (l1)? l1 : l2;
        
        while (l1 != NULL)
        {
            int sum = carry + l1->val;
            carry = (sum >= 10) ? 1 : 0;
            sum %= 10;

            lresult = new ListNode(sum);
            
            if (result == NULL)
                result = lresult;
            else
                presult->next = lresult;
            presult = lresult;

            l1 = l1->next;
        }
        
        if (carry)
        {
            lresult = new ListNode(carry);
            presult->next = lresult;
        }
        
        return result;
    }
};