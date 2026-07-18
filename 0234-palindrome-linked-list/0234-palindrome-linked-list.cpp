class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseLL(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
  /* reverse the second half then campare*/
    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = slow->next;

        while (second != NULL) {
            if (first->val != second->val) {
                slow->next = reverseLL(slow->next);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        slow->next = reverseLL(slow->next);

        return true;
    



    /* stack<int>st;
     ListNode* temp = head;
     while(temp != NULL){
         st.push(temp->val);
         temp = temp->next;
     }

     temp =head;

     while(temp != NULL){
         if(temp->val != st.top()) return false;

         temp = temp->next;
         st.pop();
     }
     return true;
   */
}
};