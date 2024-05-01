#include <iostream>
#include <stack>
#include <queue>

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
     void reorderList(ListNode* head) {
        if (head == nullptr)
            return;

        ListNode *slptr = head;
        ListNode *fptr = head;
        std::queue<ListNode*> qu;

        while((fptr) && (fptr->next))
        {
            fptr = fptr->next->next;
            qu.push(slptr);
            slptr = slptr->next;
        }
        std::stack<ListNode*> st;
        while(slptr)
        {
            st.push(slptr);
            slptr = slptr->next;
        }
        fptr = nullptr;
        while(!qu.empty())
        {
            if (fptr == nullptr)
            {
                fptr = qu.front();
                qu.pop();
            }
            else
            {
                fptr->next = qu.front();
                qu.pop();
                fptr = fptr->next;
            }
            
            slptr = st.top();
            st.pop();

            fptr->next = slptr;
            slptr->next = nullptr;
            fptr = fptr->next;
        }
        if (!st.empty())
        {
            if (fptr == nullptr)
            {
                fptr = st.top();
                st.pop();
                fptr->next = nullptr;
            }
            else
            {
                fptr->next = st.top();
                st.pop();
                fptr->next->next = nullptr;
            }
        }
        return;
    }
};

int main()
{
    Solution ob;
    {
        int array[] = {1,2,3,4};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        ob.reorderList(head);
        PrintLinkedList(head);
    }

   {
        int array[] = {1,2,3,4,5};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << std::endl;
        ob.reorderList(head);
        PrintLinkedList(head);
    }
    {
        int array[] = {1};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << std::endl;
        ob.reorderList(head);
        PrintLinkedList(head);
    }
    {
        int array[] = {1,2};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << std::endl;
        ob.reorderList(head);
        PrintLinkedList(head);
    }
    {
        int array[] = {1,2,3};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << std::endl;
        ob.reorderList(head);
        PrintLinkedList(head);
    }
    {
        int array[] = {1,2,3,4,5,6,7,8,9,10};
        ListNode* head= MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << std::endl;
        ob.reorderList(head);
        PrintLinkedList(head);
    }
    
    return 0;
}