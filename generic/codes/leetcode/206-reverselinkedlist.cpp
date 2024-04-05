#include <iostream>


/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* retnode;
        helper(head, &retnode);
        head->next = nullptr;
        return retnode;
    }
private:
    ListNode* helper(ListNode* head, ListNode** retnode)
    {
        if (head->next == nullptr)
        {
            *retnode = head;
            return head;
        }
        ListNode* lnode = helper(head->next, retnode);
        lnode->next = head;
        return head;
    }
};

void PrintLinkedList(ListNode* head)
{
    std::cout << std::endl << "LinkedList : ";
    while(head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "NULL";
}

ListNode* MakeLinkedList(int* array, int size)
{
    ListNode* head = new ListNode(array[0]);
    ListNode* thead = head;
    for (int i = 1; i < size; ++i)
    {
        thead->next = new ListNode(array[i]);
        thead = thead->next;
    }
    return head;
}

int main()
{
    Solution ob;

    {
        int array[] = {1,2,1,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,3,1,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseList(head);
        PrintLinkedList(head);
    }

    return 0;
}