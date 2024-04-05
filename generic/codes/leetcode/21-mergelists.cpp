#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* lr = nullptr;
        ListNode* lres = nullptr;

        while(l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (lr == nullptr)
                {
                    lres = lr = l1;
                }
                else
                {
                    lr->next = l1;
                    lr = lr->next;
                }
                l1 = l1->next;
            }
            else
            {
                if (lr == nullptr)
                    lres = lr = l2;
                else
                {
                    lr->next = l2;
                    lr = lr->next;
                }
                l2 = l2->next;
            }
        }
        while(l1)
        {
            if (nullptr == lr)
            {
                lres = l1;
                break;
            }
            else
            {
                lr->next = l1;
                lr = lr->next;
            }
            l1 = l1->next;
        }
        while (l2)
        {
            if (nullptr == lr)
            {
                lres = l2;
                break;
            }
            else
            {
                lr->next = l2;
                lr = lr->next;
            }
            l2 = l2->next;
        }
        return lres;
    }
};

int main()
{
    Solution ob;
    {
        int array[] = {1,2,3,4,5};
        ListNode* head1= MakeLinkedList(array, sizeof(array)/sizeof(int));
        ListNode* head2 = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }

    {
        int array[] = {1,2,3,4,5};
        int array1[] = {7};
        ListNode* head1= MakeLinkedList(array, sizeof(array)/sizeof(int));
        ListNode* head2 = MakeLinkedList(array1, sizeof(array1)/sizeof(int));
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }
    
    {
        int array[] = {1,2,3,4,5};
        ListNode* head1= MakeLinkedList(array, sizeof(array)/sizeof(int));
        ListNode* head2 = nullptr;
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }
    
    {
        ListNode* head1= nullptr;
        ListNode* head2 = nullptr;
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }
    
    {
        int array[] = {1,2,3,4,5};
        ListNode* head1= nullptr;
        ListNode* head2 = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }

    {
        int array[] = {1,2,3,4,5};
        ListNode* head1= nullptr;
        ListNode* head2 = MakeLinkedList(array, sizeof(array)/sizeof(int));
        PrintLinkedList(head1);
        PrintLinkedList(head2);
        head1 = ob.mergeTwoLists(head1, head2);
        PrintLinkedList(head1);
    }
    
    return 0;
}