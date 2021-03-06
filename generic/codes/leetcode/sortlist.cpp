#include <iostream>
#include <stack>

using std::stack;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintLinkedList(ListNode *head)
{
    std::cout << std::endl
              << "LinkedList : ";
    int count = 0;
    while (head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
        ++count;

        if (count == 15)
            break;
    }
    std::cout << "NULL";
}

ListNode *MakeLinkedList(int *array, int size)
{
    ListNode *head = new ListNode(array[0]);
    ListNode *thead = head;
    for (int i = 1; i < size; ++i)
    {
        thead->next = new ListNode(array[i]);
        thead = thead->next;
    }
    return head;
}

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *thead = head;
        stack<ListNode *> st;
        st.push(head);
        head = head->next;
        while (head)
        {
            ListNode *curr = nullptr;
            while ((st.empty() == false) && (st.top()->val > head->val))
            {
                curr = st.top();
                curr->next = head->next;
                head->next = curr;
                st.pop();
            }
            if (st.empty() == false)
                st.top()->next = head;
            if (curr == thead)
                thead = head;

            st.push(head);
            head = head->next;
        }
        return thead;
    }
};

int main()
{
    Solution ob;
    {
        int array[] = {4, 2, 1, 3};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {5, 4, 3, 2, 1};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {2, 0, 3, 1, -1};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {2};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {2, 1};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {1, 2};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);

        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        int array[] = {1, 2, 3, 4, 5};
        ListNode *head1 = MakeLinkedList(array, sizeof(array) / sizeof(int));
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    {
        ListNode *head1 = nullptr;
        PrintLinkedList(head1);
        head1 = ob.sortList(head1);
        PrintLinkedList(head1);
        std::cout << " - is Sorted";
    }
    return 0;
}