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
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        stack<ListNode*> st;

        ListNode* temp = head;
        int len = 0;

        while(temp != NULL){
            st.push(temp);
            temp = temp->next;
            len++;
        }

        temp = head;

        for(int i = 0; i < len/2; i++){

            ListNode* last = st.top();
            st.pop();

            ListNode* nextNode = temp->next;

            temp->next = last;
            last->next = nextNode;

            temp = nextNode;
        }

        temp->next = NULL;
    }
};