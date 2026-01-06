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
        if(head == NULL) return NULL;
        ListNode* temp = head;
        
        vector<int>space;
        while(temp != NULL){
            space.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0;i<space.size();i+=k){
            if(i+k<=space.size()) reverse(space.begin()+i,space.begin()+i+k);
        }
    
        temp = head;
        for(int i=0;i<space.size();i++){
             temp->val = space[i];
             temp = temp->next;
        }
        
        return head;
    }
};