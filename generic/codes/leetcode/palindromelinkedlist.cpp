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
    bool isPalindrome(ListNode* head) {
        ListNode* thead = head;
        return helper(&thead, head);
    }
private:
    bool helper(ListNode** head, ListNode* rnode)
    {
        if (rnode == nullptr)
            return true;
        bool result = helper(head, rnode->next);
        if (result)
        {
            result = ((*head)->val == rnode->val);
            *head = (*head)->next;
        }
        return result;
    }
};

ListNode* MakeLinkedList(int* array, int size)
{
    ListNode* head = new ListNode(array[0]);
    ListNode* thead = head;
    for (int i = 1; i < size; ++i)
    {
        thead->next = new ListNode(array[i]);
        thead = thead->next;
    }
    thead = head;
    std::cout << "LinkedList : ";
    while(thead != nullptr)
    {
        std::cout << thead->val << "->";
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
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }
    std::cout << std::endl;
    {
        int array[] = {1,2,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }
    std::cout << std::endl;
    {
        int array[] = {1,3,1,2,1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }
    std::cout << std::endl;
    {
        int array[] = {1};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }
    std::cout << std::endl;
    {
        int array[] = {1,2};
        ListNode* head = MakeLinkedList(array, sizeof(array)/sizeof(int));
        std::cout << " is " << (ob.isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    }

    return 0;
}