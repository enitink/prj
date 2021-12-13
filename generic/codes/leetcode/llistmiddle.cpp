/************************************SOLVED on LeeetCode*******************************************
 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while((fast != NULL) && (fast->next != NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    Solution ob;
    {
        ListNode last(5);
        ListNode node3(4, &last);
        ListNode node2(3, &node3);
        ListNode node1(2, &node2);
        ListNode head(1, &node1);
    }
    return 0;
}