class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int>st;

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

        // if (head == nullptr || head->next == nullptr)
        //     return true;
        // ListNode *slow = head, *fast = head;

        // while (fast->next && fast->next->next) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }

        // ListNode *prev = nullptr;
        // ListNode *curr = slow->next;

        // while (curr) {
        //     ListNode *front = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = front;
        // }


        // ListNode *first = head;
        // ListNode *second = prev;

        // while (second) {
        //     if (first->val != second->val)
        //         return false;

        //     first = first->next;
        //     second = second->next;
        // }

        // return true;
    }
};