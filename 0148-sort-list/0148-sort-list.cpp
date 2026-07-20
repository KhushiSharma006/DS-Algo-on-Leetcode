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

   ListNode* merge2SortedLL(ListNode* list1, ListNode* list2){
       ListNode* dummyNode = new ListNode(-1);
        
        ListNode* temp = dummyNode;

        while (list1 != NULL && list2 != NULL) {
           
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != NULL) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummyNode->next;
   }


    ListNode* findMiddle(ListNode* head){
        ListNode* temp =head;
        ListNode* slow =head;
        // to get the first middle
        ListNode* fast =head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        }

        return slow;

    }


    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

         return merge2SortedLL(left, right);



      /*  vector<int> arr;
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;*/
    }
};