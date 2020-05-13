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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return nullptr;
        ListNode* preNodes = head;
        ListNode* postNodes;

        ListNode* thead = head;
        int tm = m;
        n = n - m;
        while((--m > 0) && head != nullptr)
        {
            preNodes = head;
            head = head->next;
        }
        if (head == nullptr)
            return head;
        postNodes = head;
        while((--n >= 0) && postNodes != nullptr)
            postNodes = postNodes->next;

        if (postNodes != nullptr)
        {
            ListNode* tnode = postNodes;
            postNodes = postNodes->next;
            tnode->next = nullptr;
            
        }

        ListNode* retnode = reverseList(head);
        if (preNodes != head)
        {
            preNodes->next = retnode;
            head->next = postNodes;
        }
        else
        {
            thead = retnode;
            head->next = postNodes;
        }
        
        
        return thead;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* retnode;
        helper(head, &retnode);
        head->next = nullptr;
        return retnode;
    }

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
    std::cout << std::endl;
    {
        int array[] = {1,2,3};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 1, 2);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,3,4};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 1, 4);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,3,4,5};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 4, 5);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 1, 1);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head);
        head = ob.reverseBetween(head, 1, 1);
        PrintLinkedList(head);
    }

    return 0;
}