/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                // again move slow and fast pointer 1 step until they collide  again
                slow = head;
                while(slow != fast){
                    slow = slow-> next;
                    fast = fast->next;
                }
                return fast;
            }

        }    
         return NULL;



        /*
        // BRUTE FORCE
        unordered_set<ListNode*>st;

        while(head != NULL){
            if(st.find(head) != st.end()){
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        
        return NULL;
        */
    }
};