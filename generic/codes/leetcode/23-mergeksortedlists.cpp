#include <iostream>
#include <vector>

using std::vector;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        vector<ListNode*>::iterator itr = lists.begin();
        vector<ListNode*>::iterator eitr = lists.end();
        ListNode* merged = *itr;
        ++itr;
        for(; itr != eitr; ++itr)
        {
            merged = mergeTwoLists(merged, *itr);
        }
        return merged;
    }
private:
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
        int arra[] = {1,3,4};
        int arr[] = {5,7};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        ListNode* hea = MakeLinkedList(arra, sizeof(arra)/sizeof(int));
        ListNode* he = MakeLinkedList(arr, sizeof(arr)/sizeof(int));
        vector<ListNode*> lists = {head, hea, he};
        for(vector<ListNode*>::iterator itr = lists.begin();
            itr != lists.end(); ++itr)
            {
                PrintLinkedList(*itr);
            }
        head = ob.mergeKLists(lists);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        vector<ListNode*> lists;
        for(vector<ListNode*>::iterator itr = lists.begin();
            itr != lists.end(); ++itr)
            {
                PrintLinkedList(*itr);
            }
        ListNode* head = ob.mergeKLists(lists);
        PrintLinkedList(head);
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,3,4,5};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        vector<ListNode*> lists = {head};
        for(vector<ListNode*>::iterator itr = lists.begin();
            itr != lists.end(); ++itr)
            {
                PrintLinkedList(*itr);
            }
        head = ob.mergeKLists(lists);
        PrintLinkedList(head);
    }
    std::cout << std::endl;

    return 0;
}