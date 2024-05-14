/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* newHead = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* lstart = nullptr;
        int i ;
        while(node) {
            stack<ListNode*> st;
            lstart = node;
            for( i=0;i<k && node!=nullptr;++i) {
                st.push(node);
                node = node->next;
            }
            if(i<k) {
                cout << lstart->val << endl;
                prevNode->next = lstart;
                break;
            }
            else {
                while(!st.empty()){
                    ListNode* n = st.top();
                    st.pop();
                    if(newHead == nullptr){
                        newHead = n;
                        prevNode = newHead;
                    } else {
                        prevNode->next = n;
                        prevNode = prevNode->next;
                    }
                }
            }
        }
        if(i>=k)
            prevNode->next = nullptr;
        return newHead;
    }
};