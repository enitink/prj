/************************************SOLVED on LeeetCode*******************************************
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* removeNthFromEndHelper(ListNode* head, int& n)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* last = removeNthFromEndHelper(head->next, n);
        --n;
        if (n == 0)
        {
            return last;
        }
        else if (n == -1)
        {
            head->next = last;
        }
                
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEndHelper(head, n);
    }
};

int main()
{
    return 0;
}