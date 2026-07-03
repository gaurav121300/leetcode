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
    ListNode* helper(ListNode* node, ListNode* &head){
        if(node->next == NULL) {
            head = node;
            return node;
        }

        ListNode* x = helper(node->next,head);

        x->next = node;
        node->next=nullptr;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* prev = NULL;
         helper(head,prev);
         return prev;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr != NULL){
//             ListNode* nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//         }
//         return prev;
//     }
// };