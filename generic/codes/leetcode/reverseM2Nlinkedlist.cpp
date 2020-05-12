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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return nullptr;
        ListNode* prevNode;
        ListNode* thead = head;
        int tm = m;
        while(--m && head != nullptr)
        {
            prevNode = head;
            head = head->next;
        }
        if (head == nullptr)
            return head;

        ListNode* retnode;
        helper(head, &retnode, n-tm);
        prevNode->next = retnode;
        
        return thead;
    }
private:
    ListNode* helper(ListNode* head, ListNode** retnode, int n)
    {
        std::cout << std::endl << n;
        if ( (1 > n) || (head->next == nullptr) )
        {
            *retnode = head;
            return head;
        }

        ListNode* lnode = helper(head->next, retnode, --n);
        lnode->next = head;
        return head;
    }
};

void PrintLinkedList(ListNode* head)
{
    std::cout << std::endl << "LinkedList : ";
    int count = 0;
    while(head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
        ++count;

        if (count == 15)
         break;
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
        int array[] = {1,2,3,4,5};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 2, 4);
        PrintLinkedList(head);
    }
    // std::cout << std::endl;
    // {
    //     int array[] = {1,2,1};
    //     ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
    //     PrintLinkedList(head);
    //     head = ob.reverseBetween(head, 1, 2);
    //     PrintLinkedList(head);
    // }
    // std::cout << std::endl;
    // {
    //     int array[] = {1,2,2,1};
    //     ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
    //     PrintLinkedList(head);
    //     head = ob.reverseBetween(head, 1, 2);
    //     PrintLinkedList(head);
    // }
    // std::cout << std::endl;
    // {
    //     int array[] = {1,3,1,2,1};
    //     ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
    //     PrintLinkedList(head);
    //     head = ob.reverseBetween(head, 1, 2);
    //     PrintLinkedList(head);
    // }
    // std::cout << std::endl;
    // {
    //     int array[] = {1};
    //     ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
    //     PrintLinkedList(head);
    //     head = ob.reverseBetween(head, 1, 2);
    //     PrintLinkedList(head);
    // }
    // std::cout << std::endl;
    // {
    //     int array[] = {1,2};
    //     ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
    //     PrintLinkedList(head);
    //     head = ob.reverseBetween(head, 1, 2);
    //     PrintLinkedList(head);
    // }

    return 0;
}